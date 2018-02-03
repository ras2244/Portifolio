using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assigment9
{
    public class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            Mapper.Initialize(cfg =>
            {
                // TODO e.g. cfg.CreateMap< FROM , TO >();
                cfg.CreateMap<Models.RegisterViewModel, Models.RegisterViewModelForm>();

                cfg.CreateMap<Models.Artist, Controllers.ArtistBase>();
                cfg.CreateMap<Models.Artist, Controllers.ArtistWithDetails>();
                cfg.CreateMap<Controllers.ArtistAdd, Models.Artist>();

                cfg.CreateMap<Models.Track, Controllers.TrackBase>();
                cfg.CreateMap<Models.Track, Controllers.TrackWithDetails>();
                cfg.CreateMap<Controllers.TrackAdd, Models.Track>();

            });
        }
    }
}