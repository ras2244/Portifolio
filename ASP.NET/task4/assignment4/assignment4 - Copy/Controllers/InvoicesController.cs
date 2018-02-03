using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace assignment4.Controllers
{
    public class InvoicesController : Controller
    {
        private Manager mgm = new Manager();

        // GET: Invoices
        public ActionResult Index()
        {
            return View(mgm.InvoiceGetAll());
        }

        // GET: Invoices/Details/5
        public ActionResult Details(int? id)
        {
            var det = mgm.InvoiceGetByIdWithDetail(id.GetValueOrDefault());

            if (det == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(det);
            }
        }

        // GET: Invoices/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Invoices/Create
        [HttpPost]
        public ActionResult Create(FormCollection collection)
        {
            try
            {
                // TODO: Add insert logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Invoices/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Invoices/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Invoices/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Invoices/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
