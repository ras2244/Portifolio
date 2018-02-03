using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment1.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "This WEB Page  have the proposal of give some information about Web applications or simple web app, Its use noadays and talk about how it is being using at these days.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "For more information please get in contact with us on the following channels.";

            return View();
        }
    }
}