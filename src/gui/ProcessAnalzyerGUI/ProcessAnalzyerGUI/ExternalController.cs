using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ProcessAnalzyerGUI
{
    public static class ExternalController
    {
        [DllImport("ProcessQuery.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern string GetProcessName(uint pid);
    }
}
