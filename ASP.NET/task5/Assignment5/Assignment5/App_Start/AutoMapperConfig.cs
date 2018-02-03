using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment5
{
    public class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            Mapper.Initialize(cfg =>
            {
                cfg.CreateMap<Models.Album, Controllers.AlbumBase>();
                cfg.CreateMap<Models.MediaType, Controllers.MediaTypeBase>();
                cfg.CreateMap<Models.Artist, Controllers.ArtistBase>();
                cfg.CreateMap<Models.Track, Controllers.TrackBase>();
                cfg.CreateMap<Models.Track, Controllers.TrackWithDetail>();

                cfg.CreateMap<Controllers.TrackAdd, Models.Track>();

            });
        }
    }
}