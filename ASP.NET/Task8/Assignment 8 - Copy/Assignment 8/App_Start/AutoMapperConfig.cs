﻿using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment_8
{
    public class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            Mapper.Initialize(cfg =>
            {

                cfg.CreateMap<Models.RegisterViewModel, Models.RegisterViewModelForm>();

                cfg.CreateMap<Models.Album, Controllers.AlbumAdd>();
                cfg.CreateMap<Models.Album, Controllers.AlbumWithDetail>();
                cfg.CreateMap<Controllers.AlbumAdd, Models.Album>();
                //cfg.CreateMap<Controllers.AlbumAdd, Controllers.AlbumAddForm>();
                

                cfg.CreateMap<Models.Artist, Controllers.ArtistAdd>();
                cfg.CreateMap<Models.Artist, Controllers.ArtistWithDetail>();
                cfg.CreateMap<Controllers.ArtistAdd, Models.Artist>();

                cfg.CreateMap<Models.Track, Controllers.TrackAdd>();
                cfg.CreateMap<Models.Track, Controllers.TrackWithDetail>();
                cfg.CreateMap<Controllers.TrackAdd, Controllers.TrackEditForm>();
                cfg.CreateMap<Controllers.TrackWithDetail, Controllers.TrackEditForm>();
                cfg.CreateMap<Controllers.TrackAdd, Models.Track>();


                cfg.CreateMap<Models.Genre, Controllers.GenreBase>();

            });
        }
    }
}