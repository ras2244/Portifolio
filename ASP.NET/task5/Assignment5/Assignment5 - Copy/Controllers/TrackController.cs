using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment5.Controllers
{
    public class TrackController : Controller
    {
        // GET: Tracks

        private Manager man = new Manager();
        public ActionResult Index()
        {
            return View(man.TrackGetAllWithDetail());
        }

        // GET: Tracks/Details/5
        public ActionResult Details(int? id)
        {
            var o = man.TrackGetByIdWithDetail(id.GetValueOrDefault());
            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }

        // GET: Tracks/Create
        public ActionResult Create()
        {
            var form = new TrackAddForm();
            form.AlbumList = new SelectList(man.AlbumGetAll(), "AlbumId", "Title");
            form.MediaTypeList = new SelectList(man.MediaTypeGetAll(), "MediaTypeId", "Name");
            return View(form);
        }

        // POST: Tracks/Create
        [HttpPost]
        public ActionResult Create(TrackAddForm nTrack)
        {
            if (!ModelState.IsValid)
            {
                return View(nTrack);
            }
            else
            {
                var addedItem = man.TrackAdd(nTrack);
            }
            return RedirectToAction("Index");
        }

        // GET: Tracks/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Tracks/Edit/5
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

        // GET: Tracks/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Tracks/Delete/5
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
