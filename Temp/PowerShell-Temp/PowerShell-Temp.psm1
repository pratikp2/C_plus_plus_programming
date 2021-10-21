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
$searchResult = $updateSearcher.Search("IsInstalled=0 or IsHidden=0 or IsHidden = 1")

# save results
$missingUpdates = $searchResult.Updates | SELECT Title, Description, MsrcSeverity
$missingUpdates | Export-Csv -Path "MissingUpdates_$($env:COMPUTERNAME)_$(Get-Date -Format FileDate).csv" -NoTypeInformation
$missingUpdates | FT Title, MsrcSeverity -Auto


$historyCount       = $updateSearcher.GetTotalHistoryCount()