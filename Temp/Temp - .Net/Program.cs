using System;
using System.Collections.Generic;
using System.Data;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Net;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using System.Xml.XPath;
using CsvHelper;
using HtmlAgilityPack;
using Interop.WUApiLib;
using Microsoft.Win32;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace Temp__.Net
{
    class Program
    {
        public struct IdInfo
        {
            public string KBArticle;
            public string Severity;
        };

        public const string CONTENT_TYPE = "application/json; charset=utf-8";
        public const string TARGET_KB_ARTICLE = "KB5005568";
        public const string HTML_SEVERITY_KEY = "ScopedViewHandler_msrcSeverity";
        public const string TARGET_UPDATE_KEY = "974eb306-66c8-438b-abf9-7c9c257b1440";
        public const string HTML_URL_KB_ARTICLE = "https://www.catalog.update.microsoft.com/Search.aspx?q=";
        public const string HTML_URL_UPDATE_PAGE = "https://www.catalog.update.microsoft.com/ScopedViewInline.aspx?updateid=";
        public static string ZbookFile = @"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Zbook-OfflineScans.txt";

        public static List<string> garbage;
        public static SortedDictionary<string, List<string>> CVEHolder;
        public static List<Dictionary<string, string>> UpdateIdsHistory;
        public static List<Dictionary<string, string>> windowsUpdates;
        public static List<string> year = new List<string> { "2016", "2017", "2018", "2019", "2020", "2021" };
        public static List<string> month = new List<string> { "Jan", "Feb", "Mar", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };

        public static void GetWindowsUpdates()
        {
            Dictionary<string, string> wu;
            windowsUpdates = new List<Dictionary<string, string>>();

            UpdateSession updateSession = new UpdateSession();
            //IUpdateServiceManager2 USM = (IUpdateServiceManager2)new UpdateSession().CreateUpdateServiceManager();
            //IUpdateService US = USM.AddScanPackageService("Offline Sync Service", @"C:\Users\patilp\Downloads\wsusscn2.cab", 1);
            IUpdateSearcher2 uSearcher = (IUpdateSearcher2)updateSession.CreateUpdateSearcher();

            //uSearcher.Online = true;
            GetWindowsUpdatesHistory(uSearcher);

            Console.WriteLine("Update History");
            foreach (var Dict in UpdateIdsHistory)
            {
                foreach (var item in Dict)
                {
                    Console.WriteLine(item.Key + " : " + item.Value);
                }
                Console.WriteLine();
            }

            try
            {
                //uSearcher.ServerSelection = ServerSelection.ssDefault;
                Interop.WUApiLib.ISearchResult sResult = uSearcher.Search("IsHidden = 0 OR IsHidden = 1");

                Console.WriteLine();
                Console.WriteLine("---------------------------------------------------------");

                Console.WriteLine("Windows Update");
                foreach (Interop.WUApiLib.IUpdate5 update in sResult.Updates)
                {
                    try
                    {
                        wu = new Dictionary<string, string>();
                        wu["Title"] = update.Title;
                        wu["UpdateID"] = update.Identity.UpdateID.ToString();
                        wu["RevisionNumber"] = update.Identity.RevisionNumber.ToString();
                        //windowsUpdates.Add(wu);
                        if (!IfUpdateExist(update, UpdateIdsHistory))
                        {
                            foreach (var item in wu)
                                Console.WriteLine(item.Key + " : " + item.Value);

                            Console.WriteLine();
                        }
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine(e);
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }

        static void GetWindowsUpdatesHistory(IUpdateSearcher uSearcher)
        {
            int count = uSearcher.GetTotalHistoryCount();
            IUpdateHistoryEntryCollection collections = uSearcher.QueryHistory(0, count);
            UpdateIdsHistory = new List<Dictionary<string, string>>();
            foreach (var item in collections)
            {
                try
                {
                    IUpdateHistoryEntry2 historyEntry = (IUpdateHistoryEntry2)item;
                    Dictionary<string, string> hu = new Dictionary<string, string>();

                    hu["Title"] = historyEntry.Title;
                    hu["UpdateID"] = historyEntry.UpdateIdentity.UpdateID.ToString();
                    hu["RevisionNumber"] = historyEntry.UpdateIdentity.RevisionNumber.ToString();

                    //foreach (var item1 in hu)
                    //Console.WriteLine(item1.Key + " : " + item1.Value);

                    UpdateIdsHistory.Add(hu);
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex);
                }
                //Console.WriteLine();
            }
        }

        static public bool IfUpdateExist(IUpdate5 update, List<Dictionary<string, string>> UpdateIdsHistory)
        {
            try
            {
                foreach (var dictionary in UpdateIdsHistory.Select((value, i) => new { i, value }))
                {
                    if (dictionary.value["UpdateID"] == update.Identity.UpdateID && dictionary.value["RevisionNumber"] == update.Identity.RevisionNumber.ToString())
                    {
                        UpdateIdsHistory.RemoveAt(dictionary.i);
                        return true;
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
            return false;
        }

        public static void ProcessForCSV()
        {
            string line;

            DataTable dt = new DataTable();
            dt.Columns.Add("Name", typeof(string));
            dt.Columns.Add("Update ID", typeof(string));
            dt.Columns.Add("Revision Number", typeof(string));
            dt.Columns.Add("Online Scan", typeof(string));
            dt.Columns.Add("Offline Scan", typeof(string));
            dt.Columns.Add("Cab Scan", typeof(string));

            string name = "", updateId = "", revision = "";
            System.IO.StreamReader file = new System.IO.StreamReader(ZbookFile);
            while ((line = file.ReadLine()) != null)
            {
                if (line.StartsWith("Name : "))
                {
                    name = line.Substring(7);
                    continue;
                }
                else if (line.StartsWith("UpdateID : "))
                {
                    updateId = line.Substring(11);
                    continue;
                }
                else if (line.StartsWith("REvisionNumber : "))
                {
                    revision = line.Substring(17);
                }
                else
                    continue;

                dt.Rows.Add(name, updateId, revision, "Present", "Present", "Not Present");
            }

            ToCSV(dt, @"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\output.csv");
        }

        public static void ToCSV(DataTable dtDataTable, string strFilePath)
        {
            StreamWriter sw = new StreamWriter(strFilePath, false);
            //headers    
            for (int i = 0; i < dtDataTable.Columns.Count; i++)
            {
                sw.Write(dtDataTable.Columns[i]);
                if (i < dtDataTable.Columns.Count - 1)
                {
                    sw.Write(",");
                }
            }
            sw.Write(sw.NewLine);

            foreach (DataRow dr in dtDataTable.Rows)
            {
                for (int i = 0; i < dtDataTable.Columns.Count; i++)
                {
                    if (!Convert.IsDBNull(dr[i]))
                    {
                        string value = dr[i].ToString();
                        if (value.Contains(','))
                        {
                            value = String.Format("\"{0}\"", value);
                            sw.Write(value);
                        }
                        else
                        {
                            sw.Write(dr[i].ToString());
                        }
                    }
                    if (i < dtDataTable.Columns.Count - 1)
                    {
                        sw.Write(",");
                    }
                }
                sw.Write(sw.NewLine);
            }
            sw.Close();
        }

        public static void CompareData()
        {
            #region Read Local Updates

            GetWindowsUpdates();
            List<Dictionary<string, string>> TotalUpdates = new List<Dictionary<string, string>>();
            TotalUpdates = UpdateIdsHistory.ToList();

            foreach (var item in windowsUpdates)
                TotalUpdates.Add(item);

            #endregion

            #region Read Zbook Data 

            string line;
            string name = "";
            System.IO.StreamReader file = new System.IO.StreamReader(ZbookFile);
            while ((line = file.ReadLine()) != null)
            {
                if (line.StartsWith("Name : "))
                {
                    name = line.Substring(7);
                    foreach (var item in TotalUpdates)
                    {
                        if (name == item["Title"])
                        {
                            Console.WriteLine("Name         : " + name);
                            file.ReadLine();
                            Console.WriteLine("Zbook ID Info: " + file.ReadLine().Substring(11) + " || " + file.ReadLine().Substring(17));
                            Console.WriteLine("Local ID Info: " + item["UpdateID"] + " || " + item["RevisionNumber"]);
                            Console.WriteLine();
                            continue;
                        }
                    }

                }
            }
            #endregion
        }

        public static void SetAutoMaticUpdateSwitch()
        {
            // Automatic Update Settings
            //IAutomaticUpdates2;
            //IAutomaticUpdatesSettings3;
        }

        public static string MakeGetCall(string url)
        {
            string content = string.Empty;

            try
            {
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.AutomaticDecompression = DecompressionMethods.GZip;
                request.ContentType = CONTENT_TYPE;

                using (HttpWebResponse response = (HttpWebResponse)request.GetResponse())
                using (Stream stream = response.GetResponseStream())
                using (StreamReader reader = new StreamReader(stream))
                {
                    content = reader.ReadToEnd();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception Occured : " + ex.Message);
            }
            return content;
        }

        public static List<string> ParseHTMLAndExtractValue(string id)
        {
            List<string> values = new List<string>();

            try
            {
                var web = new HtmlWeb();
                var htmlDoc = web.Load("https://www.catalog.update.microsoft.com/ScopedViewInline.aspx?updateid=" + id);

                HtmlNode node = htmlDoc.GetElementbyId("ScopedViewHandler_msrcSeverity");

                if (node == null)
                    return values;

                string KBArticle = htmlDoc.GetElementbyId("kbDiv").InnerText.Replace("\r\n", "").Replace("KB article numbers:", "").Replace(" ", "");

                values.Add(KBArticle);
                values.Add(node.InnerText);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception Occured : " + ex.Message);
            }
            return values;
        }

        public static List<string> ParseHTMLAndExtractUpdateIds(string url)
        {
            List<string> Ids = new List<string>();
            try
            {
                var web = new HtmlWeb();
                var htmlDoc = web.Load(url);

                string docInString = htmlDoc.Text;
                if (docInString.Contains("We did not find any results for"))
                    return Ids;

                var TableNodes = htmlDoc.GetElementbyId("ctl00_catalogBody_updateMatches").SelectNodes("tr");

                foreach (var nodes in TableNodes)
                {
                    try
                    {
                        var tp3 = nodes.SelectNodes("td");
                        var tp4 = tp3[7];
                        var tp5 = tp4.SelectNodes("input");
                        if (tp5 != null)
                        {
                            var tp6 = tp5[0].Id.ToString();
                            Ids.Add(tp6);
                        }
                    }
                    catch (Exception ex)
                    {
                    }
                }


                /*var TableNodeCollection = from table in TableNode.SelectNodes("//table").Cast<HtmlNode>()
                                          from row in table.SelectNodes("tr").Cast<HtmlNode>()
                                          from cell in row.SelectNodes("td select[@class='resultsbottomBorder resultsButtonWidth']").Cast<HtmlNode>()
                                          //from id in cell.SelectNodes("input").Cast<HtmlNode>()
                                          select new { cell.Id };*/

                /*List<dynamic> datosActividades = new List<dynamic>();
                var trTablaActividades = TableNode.SelectNodes("//table").Descendants("tbody").Select(q => q.Descendants("tr")).First();
                foreach (var tr in trTablaActividades)
                {
                    var tdList = tr.Descendants("td");

                    foreach (var item in tdList)
                    {
                       
                    }
                }*/

            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception Occured : " + ex.Message);
            }
            return Ids;
        }

        public static void HandleFailureCall(string fileName)
        {
            HtmlDocument htmlDoc = null;
            string url = "https://api.msrc.microsoft.com/cvrf/v2.0/cvrf/" + fileName.Remove(8);
            try
            {
                HtmlWeb web = new HtmlWeb();
                MemoryStream memory = new MemoryStream();
                XmlTextWriter xtw = new XmlTextWriter(memory, null);
                web.LoadHtmlAsXml(url, xtw);
                memory.Position = 0;
                XmlDocument xmlDoc = new XmlDocument();
                xmlDoc.LoadXml((new StreamReader(memory)).ReadToEnd());
                htmlDoc = web.Load(url);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception while Parcing Agility Parser Occured : " + ex.Message);
            }
        }

        public static void StoreCVEFiles()
        {
            foreach (var yyyy in year)
            {
                foreach (var mmm in month)
                {
                    string Extension = string.Empty;
                    string content = MakeGetCall("https://api.msrc.microsoft.com/cvrf/v2.0/cvrf/" + yyyy + "-" + mmm);

                    if (content == string.Empty)
                        continue;

                    if (CONTENT_TYPE == "application/json; charset=utf-8")
                        Extension = ".json";
                    if (CONTENT_TYPE == "application/xml; charset=utf-8")
                    {
                        Extension = ".xml";
                        content = content.Replace("&lt;", "<");
                        content = content.Replace("&gt;", ">");
                        content = Regex.Replace(content, "(<a href[A-Za-z0-9]+)=</a>", "$1Replaced");
                    }

                    using (StreamWriter writer = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\XML Files\" + yyyy + "-" + mmm + Extension, true)) //// true to append data to the file
                    {
                        writer.WriteLine(content);
                    }
                }
            }
        }

        public static void ParceCVEJson()
        {
            if (CVEHolder == null)
                CVEHolder = new SortedDictionary<string, List<string>>();
            if (garbage == null)
                garbage = new List<string>();

            DirectoryInfo d = new DirectoryInfo(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\XML Files");
            FileInfo[] Files = d.GetFiles("*.json");

            foreach (FileInfo file in Files)
            {
                Console.WriteLine("Parcing File : " + file);
                try
                {
                    JObject JsonFile = JObject.Parse(File.ReadAllText(file.FullName.ToString()));
                    List<JToken> VulnerabilityList = JsonFile.SelectToken("Vulnerability").ToList();

                    foreach (var Vulnerability in VulnerabilityList)
                    {

                        Dictionary<string, string> ProductVsSeverity = new Dictionary<string, string>();
                        List<JToken> ThreatList = Vulnerability.SelectToken("Threats").ToList();
                        foreach (var threat in ThreatList)
                        {
                            JToken ProdToken = threat.SelectToken("ProductID");
                            if (ProdToken == null)
                                continue;

                            List<JToken> JtokenproductID = ProdToken.ToList();
                           
                            foreach (var item in JtokenproductID)
                            {
                                string productID = item.ToObject<string>();
                                var value = threat.SelectToken("Description.Value");
                                if (value == null)
                                    continue;

                                string Severity = threat.SelectToken("Description.Value").ToObject<string>();
                                if (Severity == "Important" || Severity == "Critical")
                                {
                                    if (ProductVsSeverity.ContainsKey(productID))
                                        ProductVsSeverity[productID] = ProductVsSeverity[productID] + " " +  Severity;
                                    else
                                        ProductVsSeverity.Add(productID, Severity);
                                }
                            }
                        }

                        string CVE_ID = Vulnerability.SelectToken("CVE").ToObject<string>();
                        List<JToken> RemediationsList = Vulnerability.SelectToken("Remediations").ToList();
                        foreach (var Remediation in RemediationsList)
                        {
                            String KBCode = "Not Found";
                            string KBSeverity = "";
                            var ProductToken = Remediation.SelectToken("ProductID");
                            if (ProductToken == null)
                                continue;

                            List<JToken> ProductList = Remediation.SelectToken("ProductID").ToList();
                            foreach (var item in ProductList)
                            {
                                if (ProductVsSeverity.ContainsKey(item.ToString()))
                                    KBSeverity = KBSeverity + " " + ProductVsSeverity[item.ToString()];
                            }

                            JToken KBCodeToken = Remediation.SelectToken("Description.Value");
                            if (KBCodeToken != null)
                                KBCode = KBCodeToken.ToObject<string>();

                            if (!CVEHolder.ContainsKey(KBCode) && KBCode.Length < 10)
                            {
                                List<string> CVEList = new List<string>();
                                CVEHolder.Add(KBCode, CVEList);
                            }
                            else if (KBCode.Length >= 10)
                            {
                                garbage.Add(KBCode);
                                continue;
                            }

                            /*if (!CVEHolder[KBCode].Contains(CVE_ID))
                                CVEHolder[KBCode].Add(CVE_ID);*/

                            if (!CVEHolder[KBCode].Contains(KBSeverity))
                                CVEHolder[KBCode].Add(KBSeverity);
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Exception Occured While Parcing File " + file + ":" + ex.Message);
                }
            }
        }

        public static void ParseCVEXml()
        {
            List<FileInfo> parserExcetion = new List<FileInfo>();

            if (CVEHolder == null)
                CVEHolder = new SortedDictionary<string, List<string>>();
            if (garbage == null)
                garbage = new List<string>();

            DirectoryInfo d = new DirectoryInfo(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\XML Files");
            FileInfo[] Files = d.GetFiles("*.xml");

            foreach (FileInfo file in Files)
            {
                XmlNodeList nodelist = null;
                XmlDocument doc = new XmlDocument();
                Console.WriteLine(file.FullName.ToString());
                try
                {
                    doc.Load(file.FullName.ToString());
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Exception while Parcing XML File : " + file);
                    Console.WriteLine("Message : " + ex.Message);
                    parserExcetion.Add(file);
                    HandleFailureCall(file.Name.ToString());
                    continue;
                }

                nodelist = doc.GetElementsByTagName("vuln:CVE");

                for (int i = 0; i < nodelist.Count; i++)
                {
                    var name = nodelist[i].InnerText;
                    var temp = nodelist[i].NextSibling;

                    while (true)
                    {
                        temp = temp.NextSibling;

                        if (temp.Name == "vuln:Remediations" || temp.Name == "vuln:CVE")
                            break;
                    }

                    if (temp.Name == "vuln:CVE")
                        continue;

                    var Childrenlist = temp.ChildNodes;

                    for (int j = 0; j < Childrenlist.Count; j++)
                    {
                        var attr = Childrenlist[j].ChildNodes;

                        for (int k = 0; k < attr.Count; k++)
                        {
                            if (attr[k].Name == "vuln:Description")
                            {
                                if (!CVEHolder.ContainsKey(attr[k].InnerText) && attr[k].InnerText.ToString().Length < 10)
                                {
                                    List<string> CVEList = new List<string>();
                                    CVEHolder.Add(attr[k].InnerText, CVEList);
                                }
                                else if (attr[k].InnerText.ToString().Length >= 10)
                                {
                                    garbage.Add(attr[k].InnerText);
                                    continue;
                                }

                                if (!CVEHolder[attr[k].InnerText].Contains(name))
                                    CVEHolder[attr[k].InnerText].Add(name);
                            }
                        }
                    }
                }
            }
        }

        public static void ProcessDataAndWriteToCSV()
        {
            int count = 0;
            Object ListLock = new Object();
            Object CSVLock = new Object();
            SortedDictionary<string, string> SortedKBHolder = new SortedDictionary<string, string>();
            using (var reader = new StreamReader(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\SampleUpdateIds.csv"))
            using (var writer = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\DetailedOutput.csv"))
            {
                writer.WriteLine("ID,Severity,KBArticle,CVE_ID");

                List<string> Holder = new List<string>();
                while (!reader.EndOfStream)
                {
                    Holder.Add(reader.ReadLine());
                }

                Parallel.ForEach(Holder, (id, state) =>
                {
                    var list = ParseHTMLAndExtractValue(id);

                    if (list.Count != 0)
                    {
                        /*string CVE = "";
                        lock (ListLock)
                        {
                            if (CVEHolder.ContainsKey(list[0]))
                            {
                                List<string> cveList = CVEHolder[list[0]];
                                foreach (var cve in cveList)
                                    CVE = CVE + cve;
                            }
                        }*/

                            lock (CSVLock)
                        {
                            SortedKBHolder[list[0] + " " + id] = list[1];
                            //writer.WriteLine(id + "," + list[1] + "," + list[0] /*+ "," + CVE*/);
                        }
                    }
                    Console.WriteLine(++count);
                    // Test Code
                    /*if (count > 300)
                        state.Break();*/
                });

                using (var Sortedwriter = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\SortedOutput.csv"))
                {
                    foreach (var item in SortedKBHolder)
                    {
                        Sortedwriter.WriteLine(item.Key + "," + item.Value);
                    }
                }

            }
        }

        public static void PartititionCSVInChunks()
        {
            using (var reader = new StreamReader(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\SampleUpdateIds.csv"))
            {
                int count = 1;
                while (!reader.EndOfStream)
                {
                    using (var writer = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Processed CSV\FileChunk" + count.ToString() + ".csv"))
                    {
                        int i = 0;
                        while (i < 5000 && !reader.EndOfStream)
                        {
                            writer.WriteLine(reader.ReadLine());
                            i++;
                        }
                    }
                    count++;
                }
            }
        }

        public static void ProcessCSVInChunks()
        {

            DirectoryInfo d = new DirectoryInfo(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Processed CSV");
            FileInfo[] Files = d.GetFiles("FileChunk*");

            foreach (var file in Files)
            {
                int count = 1;
                int Idcount = 0;
                Object CSVLock = new Object();
                Console.WriteLine(file.FullName.ToString());
                using (var reader = new StreamReader(file.FullName.ToString()))
                {
                    using (var writer = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Processed CSV\" + Path.GetFileNameWithoutExtension(file.Name) + "Answer" + ".csv"))
                    {
                        List<string> Holder = new List<string>();
                        while (!reader.EndOfStream)
                        {
                            Holder.Add(reader.ReadLine());
                        }

                        Parallel.ForEach(Holder, (id, state) =>
                        {
                            var list = ParseHTMLAndExtractValue(id);

                            if (list.Count != 0)
                            {
                                lock (CSVLock)
                                {
                                    writer.WriteLine(id + "," + list[1] + "," + list[0] /*+ "," + CVE*/);
                                }
                            }
                            Console.WriteLine(++Idcount);
                        });
                    }
                }
            }
        }

        public static void ConsolidateProcessedChunks()
        {

            SortedDictionary<string, string> SortedKBHolder = new SortedDictionary<string, string>();
            DirectoryInfo d = new DirectoryInfo(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Processed CSV");
            FileInfo[] Files = d.GetFiles("*Answer.csv");

            foreach (var file in Files)
            {
                using (var reader = new StreamReader(file.FullName.ToString()))
                {
                    while (!reader.EndOfStream)
                    {
                        List<string> list1 = reader.ReadLine().Split(',').ToList();
                        SortedKBHolder[list1[2] + " " + list1[0]] = list1[1];
                    }
                }
            }

            using (var writer = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Processed CSV\AnswerChunk.csv"))
            {
                writer.WriteLine("Id,Severity,KbArticle, CVE-Id");
                foreach (var update in SortedKBHolder)
                {
                    string CVEID = "";
                    List<string> list2 = update.Key.Split(' ').ToList();

                    if (CVEHolder.ContainsKey(list2[0]))
                        foreach (var cve in CVEHolder[list2[0]])
                            CVEID = CVEID + " " + cve;
                    else
                        CVEID = "Not Found";

                    writer.WriteLine(list2[1] + "," + update.Value + "," + list2[0] + "," + CVEID);
                }
            }
        }

        public static void FetchIdsUnderKBArticle()
        {
            int IdCount = 0;
            List<string> IDs = new List<string>();
            Object CSVLock = new Object();

            Parallel.ForEach(CVEHolder, (id, state) =>
            {
                string url = HTML_URL_KB_ARTICLE + "KB" + id.Key;
                List<string> temp = ParseHTMLAndExtractUpdateIds(url);

                if (temp.Count != 0)
                {
                    lock (CSVLock)
                    {
                        foreach (var item in temp)
                            IDs.Add(item + "," + id.Key);
                    }
                }
                Console.WriteLine(++IdCount);
            });

            using (var writer = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Process KBArticle\OutPut.csv"))
            {
                foreach (var item in IDs)
                    writer.WriteLine(item);
            }
        }

        public static void ProcessIdfromKBArticle()
        {
            int Idcount = 0;
            Object CSVLock = new Object();

            using (var reader = new StreamReader(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Process KBArticle\input.csv"))
            {
                using (var writer = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Process KBArticle\output.csv"))
                {
                    List<string> Holder = new List<string>();
                    while (!reader.EndOfStream)
                    {
                        Holder.Add(reader.ReadLine());
                    }

                    Parallel.ForEach(Holder, (id, state) =>
                    {
                        List<string> temp = id.Split(',').ToList();
                        var list = ParseHTMLAndExtractValue(temp[0]);

                        if (list.Count != 0)
                        {
                            lock (CSVLock)
                            {
                                writer.WriteLine(id + "," + list[1] + "," + list[0] /*+ "," + CVE*/);
                            }
                        }
                        Console.WriteLine(++Idcount);
                    });
                }
            }
        }

        public static void ExceuteMethod1()
        {
            Dictionary<string, IdInfo> ProdData = new Dictionary<string, IdInfo>();
            List<List<string>> WebData = new List<List<string>>();

            using (var prodReader = new StreamReader(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Method 1\DataSet-A-Production.csv"))
            {
                prodReader.ReadLine();
                while (!prodReader.EndOfStream)
                {
                    IdInfo dataStruct;
                    string DataLine = prodReader.ReadLine();
                    List<string> DataList = DataLine.Split(',').ToList();

                    if (!ProdData.ContainsKey(DataList[0]))
                    {
                        dataStruct.Severity = DataList[1];
                        dataStruct.KBArticle = DataList[2];
                        ProdData.Add(DataList[0], dataStruct);
                    }
                }
            }

            using (var WebReader = new StreamReader(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Method 1\DataSet-B-WebScraping.csv"))
            {
                WebReader.ReadLine();
                while (!WebReader.EndOfStream)
                {
                    string DataLine = WebReader.ReadLine();
                    List<string> DataList = DataLine.Split(',').ToList();
                    WebData.Add(DataList);
                }
            }

            using (var OutPutWriter = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Method 1\DataSet-OutPut.csv"))
            {
                OutPutWriter.WriteLine("Id,KBArticle,ProdKBArticle,WebKBArticle,Severity,ProdSeverity,WebSeverity,CVEID");
                foreach (var webItem in WebData)
                {
                    if (ProdData.ContainsKey(webItem[0]))
                    {
                        string ProdKBArticle = webItem[2];
                        string ProdSeverity = webItem[1];
                        string WebKBArticle = ProdData[webItem[0]].KBArticle;
                        string WebSeverity = ProdData[webItem[0]].Severity;
                        string KBArticle = ProdKBArticle != string.Empty ? ProdKBArticle : WebKBArticle;
                        string Severity = ProdSeverity != string.Empty ? ProdSeverity : WebSeverity;

                        OutPutWriter.WriteLine(webItem[0] + "," +
                            KBArticle + "," + ProdKBArticle + "," + WebKBArticle + "," +
                            Severity + "," + ProdSeverity + "," + WebSeverity + "," +
                            webItem[3]);
                    }
                }
            }
        }

        public static void ExceuteMethod3()
        {
            Dictionary<string, IdInfo> ProdData = new Dictionary<string, IdInfo>();

            using (var prodReader = new StreamReader(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Method 3\DataSet-A-Method1.csv"))
            {
                prodReader.ReadLine();
                while (!prodReader.EndOfStream)
                {
                    IdInfo dataStruct;
                    string DataLine = prodReader.ReadLine();
                    List<string> DataList = DataLine.Split(',').ToList();

                    if (!ProdData.ContainsKey(DataList[0]))
                    {
                        dataStruct.Severity = DataList[4];
                        dataStruct.KBArticle = DataList[1];
                        ProdData.Add(DataList[0], dataStruct);
                    }
                }
            }

            using (var OutPutWriter = new StreamWriter(@"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Method 3\DataSet-OutPut.csv"))
            {
                OutPutWriter.WriteLine("Id,KBArticle,CVEKBArticle,Severity,CVESeverity");
                foreach (var item in ProdData)
                {
                    string Severity = "Not Found";
                    string KBArticle = "Not Found";
                    if (CVEHolder.ContainsKey(item.Value.KBArticle))
                    {
                        Severity = "";
                        foreach (var se in CVEHolder[item.Value.KBArticle])
                            Severity = Severity + se.ToString();                                          
                        KBArticle = item.Value.KBArticle.ToString();
                    }

                    OutPutWriter.WriteLine(item.Key + "," + item.Value.KBArticle.ToString() + "," + KBArticle+ "," + item.Value.Severity + "," + Severity); ;
                }
            }
        }

        static void Main(string[] args)
        {
            GetWindowsUpdates();
            //ParceCVEJson();
            //ExceuteMethod3();

            /*#region Download All Json files
            Console.WriteLine("*******************************************************");
            Console.WriteLine(" Downloading CVE Document in Json Form");
            //StoreCVEFiles();
            Console.WriteLine("*******************************************************");
            Console.WriteLine();
            #endregion

            #region Populate table for CVE Codes with KB Article
            Console.WriteLine("*******************************************************");
            Console.WriteLine(" Extracting CVE Code And KB Articles from CVE Document ");
            ParceCVEJson();
            Console.WriteLine("*******************************************************");
            Console.WriteLine();
            #endregion

            #region Get KB articles of Update Ids picked from Production Data and comapre it with KB Code from CVE Table
            Console.WriteLine("*******************************************************");
            Console.WriteLine(" Extract Update ID and KB Article from Production data and Map against the KB Code and CVE IDs extraced previously");
            ProcessDataAndWriteToCSV();
            Console.WriteLine("*******************************************************");
            Console.WriteLine();
            #endregion*/

            Console.ReadLine();
        }
    }
}
