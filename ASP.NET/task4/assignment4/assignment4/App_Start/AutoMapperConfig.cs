using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace assignment4
{
    public class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            Mapper.Initialize(cfg =>
            {
                cfg.CreateMap<Models.Invoice, Controllers.InvoiceBase>();
                cfg.CreateMap<Models.Invoice, Controllers.InvoiceWithDetail>();
                cfg.CreateMap<Models.InvoiceLine, Controllers.InvoiceLineBase>();
                cfg.CreateMap<Models.InvoiceLine, Controllers.InvoiceLineWithDetail>();
            });
        }
    }
}