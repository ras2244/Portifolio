using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment3
{
    public class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            Mapper.Initialize(cfg =>
            {
                cfg.CreateMap<Models.Track, Controllers.TrackBase>();
                cfg.CreateMap<Models.Employee, Controllers.EmployeeBase>();
                cfg.CreateMap<Controllers.EmployeeBase, Controllers.EmployeeEditContactInfoForm>();
            });
        }
    }
}