$wsussCabPath = "C:\Users\patilp\Downloads\wsusscn2.cab"
Write-Host "$(Get-Date) - Loading WSUSS Cab"

# setup
$session        = New-Object -ComObject Microsoft.Update.Session 
$serviceManager = New-Object -ComObject Microsoft.Update.ServiceManager 
$packageService = $serviceManager.AddScanPackageService("Offline Sync Service", $wsussCabPath, 1) 

# create the update searcher

$updateSearcher = $session.CreateUpdateSearcher()
$updateSearcher.ServerSelection                     = 3 
$updateSearcher.ServiceID                           = $packageService.ServiceID.ToString() 
$updateSearcher.IncludePotentiallySupersededUpdates = $false
Write-Host "$(Get-Date) - Scanning $($env:COMPUTERNAME) for missing updates"

# search for missing updates: IsInstalled=0
$searchResult = $updateSearcher.Search("IsInstalled=0 Or IsHidden=0 Or IsHidden = 1")

# save results
$missingUpdates = $searchResult.Updates | SELECT Title, Description, MsrcSeverity
$missingUpdates | Export-Csv -Path "MissingUpdates_$($env:COMPUTERNAME)_$(Get-Date -Format FileDate).csv" -NoTypeInformation
$missingUpdates | FT Title, MsrcSeverity -Auto


# Query the latest 1000 History starting with the first recordp
$searchResult | ForEach-Object {
$_ | Add-Member -MemberType NoteProperty -Value $_.Identity.UpdateId -Name UpdateId
$_ | Add-Member -MemberType NoteProperty -Value $_.Identity.RevisionNumber -Name RevisionNumber
Write-Output $_
}

$historyCount       = $updateSearcher.GetTotalHistoryCount()
$HistoryCollection = $updateSearcher.QueryHistory(0, $historyCount);
$HistoryCollection | FT Title, UpdateID -Auto


# Convert Wua History ResultCode to a Name # 0, and 5 are not used for history # See https://msdn.microsoft.com/en-us/library/windows/desktop/aa387095(v=vs.85).aspx

function Convert-WuaResultCodeToName
{
param( [Parameter(Mandatory=$true)]
[int] $ResultCode
)
$Result = $ResultCode
switch($ResultCode)
{
2
{
$Result = "Succeeded"
}
3
{
$Result = "Succeeded With Errors"
}
4
{
$Result = "Failed"
}
}
return $Result
}
function Get-WuaHistory
{
# Get a WUA Session
$session = (New-Object -ComObject 'Microsoft.Update.Session')

# Query the latest 1000 History starting with the first recordp
$history = $session.QueryHistory("",0,50) | ForEach-Object {
$Result = Convert-WuaResultCodeToName -ResultCode $_.ResultCode

# Make the properties hidden in com properties visible.
$_ | Add-Member -MemberType NoteProperty -Value $Result -Name Result
$Product = $_.Categories | Where-Object {$_.Type -eq 'Product'} | Select-Object -First 1 -ExpandProperty Name
$_ | Add-Member -MemberType NoteProperty -Value $_.UpdateIdentity.UpdateId -Name UpdateId
$_ | Add-Member -MemberType NoteProperty -Value $_.UpdateIdentity.RevisionNumber -Name RevisionNumber
$_ | Add-Member -MemberType NoteProperty -Value $Product -Name Product -PassThru
Write-Output $_
}

#Remove null records and only return the fields we want
$history |
Where-Object {![String]::IsNullOrWhiteSpace($_.title)} |
Select-Object Result, Date, Title, SupportUrl, Product, UpdateId, RevisionNumber
}

