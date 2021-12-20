using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Temp__.Net
{
    public class Title
    {
    };
    public class Notes
    {
        [JsonProperty("Title")]
        public string Title;

        [JsonProperty("Type")]
        public int Type;

        [JsonProperty("Ordinal")]
        public string Ordinal;
    };
    class Remediations
    {
        public string URL;
        public string Description;
    };

    public class Vulnerability
    {
        [JsonProperty("Title")]
        public Title title;

        [JsonProperty("Notes")]
        Notes[] notes;

        [JsonProperty("DiscoveryDateSpecified")]
        public bool DiscoveryDateSpecified;

        [JsonProperty("ReleaseDateSpecified")]
        public bool ReleaseDateSpecified;

        [JsonProperty("CVE")]
        public string CVE;
    };
}
