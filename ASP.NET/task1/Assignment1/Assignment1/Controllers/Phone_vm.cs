using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment1.Controllers
{

    //ctor
    public class PhoneBase
    {
        public PhoneBase()
        {
            DateRelease = DateTime.Now;
            PhoneName = "";
            Manufacturer = "";
        }


        //Properties
        public int Id { get; set; }
        public string PhoneName { get; set; }
        public string Manufacturer { get; set; }
        public DateTime DateRelease { get; set; }
        public int MSRP { get; set; }
        public double ScreenSize { get; set; }

    }
}