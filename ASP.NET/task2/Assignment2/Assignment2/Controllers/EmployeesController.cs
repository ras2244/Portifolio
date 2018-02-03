using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment2.Controllers
{

    public class employeesController : Controller
    {
        private Manager mgm = new Manager();

        // GET: employees
        public ActionResult Index()
        {
            return View(mgm.EmployeeGetAll());
        }

        // GET: employees/Details/5
        public ActionResult Details(int? id)
        {
            var det = mgm.EmployeeGetOne(id.GetValueOrDefault());

            if (det == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(det);
            }
        }

        // GET: employees/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: employees/Create
        [HttpPost]
        public ActionResult Create(EmployeeAdd_vm newEmp)
        {
            if (!ModelState.IsValid)

            {
                return View(newEmp);
            }

            var addedItem = mgm.EmployeeAdd(newEmp);
            if (addedItem==null)
            {
                return View(newEmp);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.EmployeeId });
            }
        }

        // GET: employees/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: employees/Edit/5
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

        // GET: employees/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: employees/Delete/5
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
