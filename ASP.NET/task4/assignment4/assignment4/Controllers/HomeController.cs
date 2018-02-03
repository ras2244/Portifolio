using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace assignment4.Controllers
{
    public class HomeController : Controller
    {
        // Reference to the data manager
        private Manager mgm = new Manager();

        public ActionResult Index()
        {
            return View(mgm.InvoiceGetAll());
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}