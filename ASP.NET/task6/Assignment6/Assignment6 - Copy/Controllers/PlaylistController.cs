using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using AutoMapper;

namespace Assignment6.Controllers
{
    public class PlaylistController : Controller
    {
        private Manager mgm = new Manager();
        public ActionResult Index()
        {
            return View(mgm.PlaylistGetAllWithDetail());
        }

        // GET: Playlist/Details/5
        public ActionResult Details(int? id)
        {
            var o = mgm.PlaylistGetByIdWithDetail(id.GetValueOrDefault());

            if (o == null)
            { return HttpNotFound(); }
            else
            { return View(o); }
        }


        // GET: Playlist/Edit/5        

        public ActionResult Edit(int? id)
        {
            var o = mgm.PlaylistGetByIdWithDetail(id.GetValueOrDefault());

            if (o == null) { return HttpNotFound(); }

            else
            {
                // A form, based on the fetched matching object
                var form = Mapper.Map<PlaylistBase, PlaylistEditTrackForm>(o);

                List<TrackBase> tracks = new List<TrackBase>();

                //Select() method allows us to select/return/use only some properties from the source
                var selectedTracks = o.Tracks.Select(t => t.TrackId);

                foreach (var item in o.Tracks)
                {
                    tracks.Add(item);
                }

                form.TrackOnPlaylist = tracks;

                form.TrackList = new MultiSelectList
                                (items: mgm.TrackGetAll(),
                                dataValueField: "TrackId",
                                dataTextField: "NameFull",
                                selectedValues: selectedTracks);

                return View(form);
            }
        }

        [HttpPost]
        public ActionResult Edit(int? id, PlaylistEditTrack newItem)
        {
            if (!ModelState.IsValid)
            {
                return RedirectToAction("edit", new
                {
                    id = newItem.Id
                });
            }

            if (id.GetValueOrDefault() != newItem.Id)
            {
                return RedirectToAction("index");
            }

            var editedItem = mgm.PlaylistEditTracks(newItem);

            if (editedItem == null)
            {
                return RedirectToAction("edit", new { id = newItem.Id });
            }
            else
            {
                return RedirectToAction("details", new { id = newItem.Id });
            }
        }
    }
}
