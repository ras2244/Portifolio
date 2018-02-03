using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using assignment4.Models;

namespace assignment4.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {      

        }


        public IEnumerable<InvoiceBase> InvoiceGetAll()
        {
            return Mapper.Map<IEnumerable<Invoice>, IEnumerable<InvoiceBase>>(ds.Invoices.OrderByDescending(t => t.InvoiceId));
        }

        public InvoiceBase InvoiceGetOne(int id)
        {
            var inv = ds.Invoices.Find(id);
            return (inv == null) ? null : Mapper.Map<Invoice, InvoiceBase>(inv);
        }



        public InvoiceWithDetail InvoiceGetByIdWithDetail(int id)
        {
            var incdet = ds.Invoices
                         .Include("Customer.Employee")
                         .Include("InvoiceLines.Track.Album.Artist")
                         .Include("InvoiceLines.Track.MediaType")
                         .SingleOrDefault(t => t.InvoiceId == id);

            return (incdet==null) ? null : Mapper.Map<Invoice, InvoiceWithDetail>(incdet);
        }



    }
}   