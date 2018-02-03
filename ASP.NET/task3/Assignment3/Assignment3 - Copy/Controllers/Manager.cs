using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment3.Models;

namespace Assignment3.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            
        }

        public IEnumerable<EmployeeBase> EmployeeGetAll()
        {
            return Mapper.Map<IEnumerable<Employee>, IEnumerable<EmployeeBase>>(ds.Employees);
        }

        public EmployeeBase EmplyeeGetOne(int id)
        {
            var obj = ds.Employees.Find(id);
            return (obj == null) ? null : Mapper.Map<Employee, EmployeeBase>(obj);        
        }

        internal object EmployeeEditContactInfo(int frm)
        {
            throw new NotImplementedException();
        }

        public EmployeeBase EmployeeEditContactInfo (EmployeeEditContactInfo index)
        {
            var edindex = ds.Employees.Find(index.EmployeeId);

            if (edindex == null)
            {
                return null;
            }
            else
            {
                ds.Entry(edindex).CurrentValues.SetValues(index);
                ds.SaveChanges();
                return Mapper.Map<Employee, EmployeeBase>(edindex);
            }
        }

        public IEnumerable<TrackBase> TracksGetAll()
        {
            var info = ds.Tracks.OrderBy(x => x.TrackId);
            return Mapper.Map < IEnumerable < Track >, IEnumerable < TrackBase >> (info);
        }

        public IEnumerable<TrackBase> GetAllPopTracks()
        {
            //GenreId is 9, sorted ascending by track Name

            var pops = ds.Tracks
                           .Where(X => X.GenreId == 9)
                           .OrderBy(x => x.Name);
            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(pops);

        }

        //Composer contains “Jon Lord”, sorted ascending by TrackId

        public IEnumerable<TrackBase> GetDeepPurpleTracks()
        {
            var jonh = ds.Tracks
                           .Where(X => X.Composer.Contains("Jon Lord"))
                           .OrderBy(x => x.TrackId);
            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(jonh);
        }


        public IEnumerable<TrackBase> GetTop100LongestTracks()
        {
            var longst = ds.Tracks
                           .OrderByDescending(x => x.Milliseconds).Take(100);
            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(longst);
        }


        // Add methods below
        // Controllers will call these methods
        // Ensure that the methods accept and deliver ONLY view model objects and collections
        // The collection return type is almost always IEnumerable<T>

        // Suggested naming convention: Entity + task/action
        // For example:
        // ProductGetAll()
        // ProductGetById()
        // ProductAdd()
        // ProductEdit()
        // ProductDelete()






    }
}