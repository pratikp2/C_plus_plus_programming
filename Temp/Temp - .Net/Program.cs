using System;
using System.Collections.Generic;
using System.Data;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Net;
using System.Xml;
using CsvHelper;
using HtmlAgilityPack;
using Interop.WUApiLib;
using Microsoft.Win32;

namespace Temp__.Net
{
    class Program
    {
        public static string ZbookFile = @"C:\Users\patilp\OneDrive - HP Inc\Desktop\Windows UpdaTE poc\Zbook-OfflineScans.txt";

        public static List<Dictionary<string, string>> UpdateIdsHistory;
        public static List<Dictionary<string, string>> windowsUpdates;


        public const string HTML_URL_UPDATE_PAGE = "https://www.catalog.update.microsoft.com/ScopedViewInline.aspx?updateid=";
        public const string HTML_URL_KB_ARTICLE = "https://www.catalog.update.microsoft.com/Search.aspx?q=";
        public const string HTML_SEVERITY_KEY = "ScopedViewHandler_msrcSeverity";
        public const string TARGET_UPDATE_KEY = "974eb306-66c8-438b-abf9-7c9c257b1440";
        public const string TARGET_KB_ARTICLE = "KB5005568";


        class unit
        {
            public string name = "";
            public string update = "";
        };

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

            try
            {
                int count = 1;
                //uSearcher.ServerSelection = ServerSelection.ssDefault;
                Interop.WUApiLib.ISearchResult sResult = uSearcher.Search("IsHidden = 0 OR IsHidden = 1");
                foreach (Interop.WUApiLib.IUpdate5 update in sResult.Updates)
                {
                    try
                    {
                        wu = new Dictionary<string, string>();
                        wu["Title"] = update.Title;
                        wu["UpdateID"] = update.Identity.UpdateID.ToString();
                        wu["RevisionNumber"] = update.Identity.RevisionNumber.ToString();
                        //windowsUpdates.Add(wu);

                        /*if (IfUpdateExist(update, UpdateIdsHistory))
                            foreach (var item in wu)
                                Console.WriteLine(item.Key + " : " + item.Value);*/
                        //if (!IfUpdateExist(update, UpdateIdsHistory))
                        // windowsUpdates.Add(wu);

                        Console.WriteLine(count + " - " + update.Title);
                        //Console.WriteLine("MSRC Severity: " + update.MsrcSeverity);

                        Console.Write("KBArticleIDs :   ");
                        foreach (var item in update.KBArticleIDs)
                            Console.WriteLine(item);

                        Console.Write("CVE Ids      :   ");
                        foreach (var item in update.CveIDs)
                            Console.Write(item + ", ");

                        ICategoryCollection tp = update.Categories;
                        Console.WriteLine();

                        for (int i = 0; i < tp.Count; i++)
                        {
                            Console.WriteLine("CAtegoryName      :   " + tp[i].Name.ToString());
                            Console.WriteLine("ID      :   " + tp[i].CategoryID.ToString());
                            Console.WriteLine("Type      :   " + tp[i].Type.ToString());
                            Console.WriteLine("Des      :   " + tp[i].Description.ToString());
                        }

                        Console.WriteLine();
                        Console.WriteLine();
                        count++;
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
            string html = string.Empty;

            try
            {
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.AutomaticDecompression = DecompressionMethods.GZip;

                using (HttpWebResponse response = (HttpWebResponse)request.GetResponse())
                using (Stream stream = response.GetResponseStream())
                using (StreamReader reader = new StreamReader(stream))
                {
                    html = reader.ReadToEnd();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception Occured : " + ex.Message);
            }
            return html;
        }

        public static string ParseHTMLAndExtractValue(string url, string Key)
        {
            try
            {
                var web = new HtmlWeb();
                var htmlDoc = web.Load(url);

                HtmlNode node = htmlDoc.GetElementbyId(Key);
                return node.InnerText;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception Occured : " + ex.Message);
            }
            return string.Empty;
        }

        public static List<string> ParseHTMLAndExtractUpdateIds(string url)
        {
            List<string> Ids = new List<string>();
            try
            {
                var web = new HtmlWeb();
                var htmlDoc = web.Load(url);
                var TableNodes = htmlDoc.GetElementbyId("ctl00_catalogBody_updateMatches").SelectNodes("tr");

                foreach (var nodes in TableNodes)
                {
                    try
                    {
                        var tp3 = nodes.SelectNodes("td");
                        var tp4 = tp3[7];
                        var tp5 = tp4.SelectNodes("input");
                        var tp6 = tp5[0].Id.ToString();

                        Ids.Add(tp6);
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

        static void Main(string[] args)
        {
            GetWindowsUpdates();

            /*string Severity = string.Empty, url = string.Empty;

            // Extract Via Update ID
            url = HTML_URL_UPDATE_PAGE + TARGET_UPDATE_KEY;
            Severity = ParseHTMLAndExtractValue(url, HTML_SEVERITY_KEY);

            // Extract Via KB Article
            url = HTML_URL_KB_ARTICLE + TARGET_KB_ARTICLE;
            List<string> IdList =  ParseHTMLAndExtractUpdateIds(url);
            Dictionary<string, string> severityMap = new Dictionary<string, string>();
            foreach (var item in IdList)
            {
                url = HTML_URL_UPDATE_PAGE + item;
                severityMap[item] = ParseHTMLAndExtractValue(url, HTML_SEVERITY_KEY);
            }

            // Extract Via Windows Version*/

            Console.ReadLine();
        }
    }
}
