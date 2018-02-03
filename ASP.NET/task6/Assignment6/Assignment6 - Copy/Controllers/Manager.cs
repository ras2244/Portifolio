using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using AutoMapper;
using Assignment6.Models;

namespace Assignment6.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            
        }

        public IEnumerable<PlaylistBase> PlayListGetAll()
        {
            return Mapper.Map<IEnumerable<Playlist>, IEnumerable<PlaylistBase>>(ds.Playlists.OrderBy(t => t.Name));
        }

        public PlaylistWithDetail PlaylistGetByIdWithDetail(int id)
        {
            
            var det = ds.Playlists.Include("Tracks").SingleOrDefault(t => t.PlaylistId == id);
            return (det == null) ? null : Mapper.Map<Playlist, PlaylistWithDetail>(det);
        }

        public IEnumerable<PlaylistWithDetail> PlaylistGetAllWithDetail()
        {
            var det = ds.Playlists.Include("Tracks").OrderBy(t => t.PlaylistId);
            return Mapper.Map<IEnumerable<Playlist>, IEnumerable<PlaylistWithDetail>>(det);
        }

        public IEnumerable<TrackBase> TrackGetAll()
        {
            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(ds.Tracks.OrderBy(x => x.Name));
        }

        public PlaylistWithDetail PlaylistEditTracks(PlaylistEditTrack newItem)
        {
            var detTrack = ds.Playlists.Include("Tracks").SingleOrDefault(t => t.PlaylistId == newItem.Id);

            if (detTrack == null) { return null; }

            else
            {
                detTrack.Tracks.Clear();

                foreach (var track in newItem.TrackIds)
                {
                    var a = ds.Tracks.Find(track);
                    detTrack.Tracks.Add(a);
                }
                ds.SaveChanges();

                return Mapper.Map<Playlist, PlaylistWithDetail>(detTrack);
            }
        }
    }
}