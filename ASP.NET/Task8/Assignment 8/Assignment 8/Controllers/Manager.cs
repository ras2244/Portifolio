using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_8.Models;
using System.Security.Claims;

namespace Assignment_8.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private ApplicationDbContext ds = new ApplicationDbContext();

        // Request user property...

        // Backing field for the property
        private RequestUser _user;

        // Getter only, no setter
        public RequestUser User
        {
            get
            {
                // On first use, it will be null, so set its value
                if (_user == null)
                {
                    _user = new RequestUser(HttpContext.Current.User as ClaimsPrincipal);
                }
                return _user;
            }
        }

        // Default constructor...
        public Manager()
        {
            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;

            // If necessary, add constructor code here


        }

        // ############################################################
        // RoleClaim

        public List<string> RoleClaimGetAllStrings()
        {
            return ds.RoleClaims.OrderBy(r => r.Name).Select(r => r.Name).ToList();
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

        /* ---Track Methods--- */


        public IEnumerable<TrackAdd> TrackGetAll()
        {
            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackAdd>>(ds.Tracks.OrderBy(x => x.Name));
        }
        public IEnumerable<TrackAdd> TrackGetAllByArtistId(int id)

        {

            // Fetch the artist
            var o = ds.Artists.Include("Albums.Tracks").SingleOrDefault(a => a.Id == id);

            // Continue?
            if (o == null) { return null; }

            // Create a collection to hold the results
            var c = new List<Track>();

            // Go through each album, and get the tracks
            foreach (var album in o.Albums)
            {
                c.AddRange(album.Tracks);
            }

            // Remove duplicates
            c = c.Distinct().ToList();

            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackAdd>>(c.OrderBy(t => t.Name));
        }

        public TrackWithDetail TrackGetByIdWithDetail(int id)
        {
            var o = ds.Tracks.Include("Albums.Artists").SingleOrDefault(t => t.Id == id);



            // Create the result collection

            var result = Mapper.Map<Track, TrackWithDetail>(o);

            // Fill in the album names
            result.AlbumNames = o.Albums.Select(x => x.Name);
            return result;
            // return (o == null) ? null : Mapper.Map<Track, TrackWithDetail>(o);
        }

        public TrackAdd TrackAdd(TrackAdd newItem)
        {
            var addedItem = ds.Tracks.Add(Mapper.Map<TrackAdd, Track>(newItem));
            var findGenre = ds.Genres.Find(newItem.GenreId);

            addedItem.Genre = findGenre.Name;
            ds.SaveChanges();

            return (addedItem == null) ? null : Mapper.Map<Track, TrackAdd>(addedItem);
        }

        public TrackWithDetail TrackEdit(TrackEdit newItem)
        {
            var o = ds.Tracks.Include("Albums").SingleOrDefault(x => x.Id == newItem.Id);

            if (o == null)
            {
                return null;
            }
            else
            {
                ds.Entry(o).CurrentValues.SetValues(newItem);
                ds.SaveChanges();

                return Mapper.Map<Track, TrackWithDetail>(o);
            }
        }

        public bool TrackDelete(int id)
        {
            var itemToDelete = ds.Tracks.Find(id);

            if (itemToDelete == null)
            {
                return false;
            }
            else
            {
                ds.Tracks.Remove(itemToDelete);
                ds.SaveChanges();

                return true;
            }
        }
        /* -!- End Track Methods-!- */

        /* --- Album Methods--- */
        public IEnumerable<AlbumAdd> AlbumGetAll()
        {
            return Mapper.Map<IEnumerable<Album>, IEnumerable<AlbumAdd>>(ds.Albums.OrderBy(x => x.Name));
        }


        public AlbumWithDetail AlbumGetByIdWithDetail(int id)
        {
            var o = ds.Albums.Include("Artists").Include("Tracks").SingleOrDefault(x => x.Id == id);
            if (o == null)
            {
                return null;
            }
            else
            {
                // Create the result collection
                var result = Mapper.Map<Album, AlbumWithDetail>(o);
                // Fill in the album names
                result.ArtistNames = o.Artists.Select(x => x.Name);
                return result;
            }
        }

        public AlbumAdd AlbumAdd(AlbumAdd newItem)
        {
            // Attempt to add the new item
            var addedItem = ds.Albums.Add(Mapper.Map<AlbumAdd, Album>(newItem));
            //var findGenre = ds.Genres.Find(newItem.GenreId);

            //foreach (var item in newItem.TrackIds)
            //{
            //    var a = ds.Tracks.Find(item);
            //    addedItem.Tracks.Add(a);
            //}

            foreach (var item in newItem.ArtistIds)
            {
                var a = ds.Artists.Find(item);
                addedItem.Artists.Add(a);
            }

            // Set the associated item property
            addedItem.Coordinator = User.Name;
            ds.SaveChanges();

            return (addedItem == null) ? null : Mapper.Map<Album, AlbumAdd>(addedItem);
        }


        /* -!- End Album Methods-!- */

        /* ---Artist Methods--- */

        public IEnumerable<ArtistAdd> ArtistGetAll()
        {
            return Mapper.Map<IEnumerable<Artist>, IEnumerable<ArtistAdd>>(ds.Artists.OrderBy(x => x.Name));
        }

        public ArtistWithDetail ArtistGetByIdWithDetail(int id)
        {
            var o = ds.Artists.Include("Albums").SingleOrDefault(a => a.Id == id);
            return (o == null) ? null : Mapper.Map<Artist, ArtistWithDetail>(o);
        }

        public ArtistAdd ArtistAdd(ArtistAdd newItem)
        {
            var addedItem = ds.Artists.Add(Mapper.Map<ArtistAdd, Artist>(newItem));
            var findGenre = ds.Genres.Find(newItem.GenreId);

            addedItem.Genre = findGenre.Name;
            ds.SaveChanges();

            return (addedItem == null) ? null : Mapper.Map<Artist, ArtistAdd>(addedItem);
        }

        /* -!-End Artist Methods-!- */

        /* --- Genre Methods--- */

        public IEnumerable<GenreBase> GenreGetAll()
        {
            return Mapper.Map<IEnumerable<Genre>, IEnumerable<GenreBase>>(ds.Genres.OrderBy(x => x.Name));
        }

        /* -!-End Genre Methods-!- */




        // Add some programmatically-generated objects to the data store
        // Can write one method, or many methods - your decision
        // The important idea is that you check for existing data first
        // Call this method from a controller action/method

        public bool LoadDataRoleClaim()
        {
            if (ds.RoleClaims.Count() == 0)
            {
                ds.RoleClaims.Add(new Models.RoleClaim { Name = "Executive" });
                ds.RoleClaims.Add(new Models.RoleClaim { Name = "Coordinator" });
                ds.RoleClaims.Add(new Models.RoleClaim { Name = "Clerk" });
                ds.RoleClaims.Add(new Models.RoleClaim { Name = "Staff" });

                Console.WriteLine("Hello World!");

                return true;
            }
            else
            {
                Console.WriteLine("Hello World!");
                return false;
               
            }
        }

        public bool LoadDataGenre()
        {

            if (ds.Genres.Count() > 0) { return false; }

            else
            {
                ds.Genres.Add(new Genre { Name = "Hip-Hop" });
                ds.Genres.Add(new Genre { Name = "Pop music" });
                ds.Genres.Add(new Genre { Name = "Rock" });
                ds.Genres.Add(new Genre { Name = "Alternative Rock" });
                ds.Genres.Add(new Genre { Name = "Indie" });
                ds.Genres.Add(new Genre { Name = "Country" });
                ds.Genres.Add(new Genre { Name = "Classical" });
                ds.Genres.Add(new Genre { Name = "Jazz" });
                ds.Genres.Add(new Genre { Name = "Electronic" });
                ds.Genres.Add(new Genre { Name = "Techno" });

                ds.SaveChanges();
                return true;
            }
        }

        public bool LoadDataArtist()
        {

            if (ds.Artists.Count() > 0) { return false; }

            else
            {
                var pop = ds.Genres.SingleOrDefault(a => a.Name == "Pop Music");
                

                ds.Artists.Add(new Artist
                {
                    Name = "Shawn Mendes",
                    BirthName = "Shawn Mendes",
                    BirthOrStartDate = new DateTime(1998, 8, 8),
                    Executive = "Ricardo Leal",
                    Genre = pop.Name,
                    UrlArtist = "https://itunes.apple.com/ca/artist/shawn-mendes/890403665"
                });

                ds.Artists.Add(new Artist
                {
                    Name = "Taylor Swift",
                    BirthName = "Taylor Swift",
                    BirthOrStartDate = new DateTime(1989, 12, 13),
                    Executive = "Ricardo Leal",
                    Genre = pop.Name,
                    UrlArtist = "https://itunes.apple.com/ca/artist/taylor-swift/159260351"
                });

                ds.Artists.Add(new Artist
                {
                    Name = "Maroon 5",
                    BirthName = "Maroon 5",
                    BirthOrStartDate = new DateTime(1999, 9, 10),
                    Executive = "Ricardo Leal",
                    Genre = pop.Name,
                    UrlArtist = "https://itunes.apple.com/ca/artist/maroon-5/1798556"
                });

                ds.SaveChanges();
                return true;
            }
        }

        public bool LoadDataAlbum()
        {

            if (ds.Albums.Count() > 0) { return false; }

            else
            {
                var shawn = ds.Artists.SingleOrDefault(a => a.Name == "Shawn Mendes");
                var taylor = ds.Artists.SingleOrDefault(a => a.Name == "Taylor Swift");
                var pop = ds.Genres.SingleOrDefault(a => a.Name == "Pop Music");

                var sinatra = ds.Albums.Add(new Album
                {
                    Name = "MTV Unplugged",
                    Coordinator = "Ricardo Leal",
                    Genre = pop.Name,
                    ReleaseDate = new DateTime(2017, 11, 3),
                    Artists = new List<Artist> { shawn },
                    UrlAlbum = "https://itunes.apple.com/ca/album/mtv-unplugged/1296935050"
                });

                var pressure = ds.Albums.Add(new Album
                {
                    Name = "Reputation",
                    Coordinator = "Ricardo Leal",
                    Genre = pop.Name,
                    ReleaseDate = new DateTime(2017, 11, 10),
                    Artists = new List<Artist> { taylor },
                    UrlAlbum = "https://itunes.apple.com/ca/album/reputation/1274999981"
                });

                ds.SaveChanges();
                return true;
            }
        }
        public bool LoadDataTrack()
        {

            if (ds.Tracks.Count() > 0) { return false; }

            else
            {
                var shawn = ds.Artists.SingleOrDefault(a => a.Name == "Shawn Mendes");
                var taylor = ds.Artists.SingleOrDefault(a => a.Name == "Taylor Swift");
                var pop = ds.Genres.SingleOrDefault(a => a.Name == "Pop Music");
                var mtv = ds.Albums.SingleOrDefault(a => a.Name == "MTV Unplugged");
                var reputation = ds.Albums.SingleOrDefault(a => a.Name == "Reputation");

                ds.Tracks.Add(new Track
                {
                    Name = "Ruin",
                    Clerk = "clerk@example.com",
                    Composers = shawn.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { mtv }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Bad Reputation",
                    Clerk = "clerk@example.com",
                    Composers = shawn.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { mtv }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Don`t be Fool",
                    Clerk = "clerk@example.com",
                    Composers = shawn.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { mtv }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Roses",
                    Clerk = "clerk@example.com",
                    Composers = shawn.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { mtv }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Delicate",
                    Clerk = "clerk@example.com",
                    Composers = taylor.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { reputation }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "I Did Something Bad",
                    Clerk = "clerk@example.com",
                    Composers = taylor.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { reputation }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "So It Goes",
                    Clerk = "clerk@example.com",
                    Composers = taylor.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { reputation }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Gorgeous",
                    Clerk = "clerk@example.com",
                    Composers = taylor.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { reputation }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "Dress",
                    Clerk = "clerk@example.com",
                    Composers = taylor.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { reputation }
                });

                ds.Tracks.Add(new Track
                {
                    Name = "King Of My Heart",
                    Clerk = "clerk@example.com",
                    Composers = taylor.Name,
                    Genre = pop.Name,
                    Albums = new List<Album> { reputation }
                });

                ds.SaveChanges();
                return true;
            }
        }

        public bool RemoveData()
        {
            try
            {
                foreach (var e in ds.RoleClaims)
                {
                    ds.Entry(e).State = System.Data.Entity.EntityState.Deleted;
                }
                ds.SaveChanges();

                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        public bool RemoveDatabase()
        {
            try
            {
                return ds.Database.Delete();
            }
            catch (Exception)
            {
                return false;
            }
        }

    }

    // New "RequestUser" class for the authenticated user
    // Includes many convenient members to make it easier to render user account info
    // Study the properties and methods, and think about how you could use it

    // How to use...

    // In the Manager class, declare a new property named User
    //public RequestUser User { get; private set; }

    // Then in the constructor of the Manager class, initialize its value
    //User = new RequestUser(HttpContext.Current.User as ClaimsPrincipal);

    public class RequestUser
    {
        // Constructor, pass in the security principal
        public RequestUser(ClaimsPrincipal user)
        {
            if (HttpContext.Current.Request.IsAuthenticated)
            {
                Principal = user;

                // Extract the role claims
                RoleClaims = user.Claims.Where(c => c.Type == ClaimTypes.Role).Select(c => c.Value);

                // User name
                Name = user.Identity.Name;

                // Extract the given name(s); if null or empty, then set an initial value
                string gn = user.Claims.SingleOrDefault(c => c.Type == ClaimTypes.GivenName).Value;
                if (string.IsNullOrEmpty(gn)) { gn = "(empty given name)"; }
                GivenName = gn;

                // Extract the surname; if null or empty, then set an initial value
                string sn = user.Claims.SingleOrDefault(c => c.Type == ClaimTypes.Surname).Value;
                if (string.IsNullOrEmpty(sn)) { sn = "(empty surname)"; }
                Surname = sn;

                IsAuthenticated = true;
                // You can change the string value in your app to match your app domain logic
                IsAdmin = user.HasClaim(ClaimTypes.Role, "Admin") ? true : false;
            }
            else
            {
                RoleClaims = new List<string>();
                Name = "anonymous";
                GivenName = "Unauthenticated";
                Surname = "Anonymous";
                IsAuthenticated = false;
                IsAdmin = false;
            }

            // Compose the nicely-formatted full names
            NamesFirstLast = $"{GivenName} {Surname}";
            NamesLastFirst = $"{Surname}, {GivenName}";
        }

        // Public properties
        public ClaimsPrincipal Principal { get; private set; }
        public IEnumerable<string> RoleClaims { get; private set; }

        public string Name { get; set; }

        public string GivenName { get; private set; }
        public string Surname { get; private set; }

        public string NamesFirstLast { get; private set; }
        public string NamesLastFirst { get; private set; }

        public bool IsAuthenticated { get; private set; }

        public bool IsAdmin { get; private set; }

        public bool HasRoleClaim(string value)
        {
            if (!IsAuthenticated) { return false; }
            return Principal.HasClaim(ClaimTypes.Role, value) ? true : false;
        }

        public bool HasClaim(string type, string value)
        {
            if (!IsAuthenticated) { return false; }
            return Principal.HasClaim(type, value) ? true : false;
        }
    }

}