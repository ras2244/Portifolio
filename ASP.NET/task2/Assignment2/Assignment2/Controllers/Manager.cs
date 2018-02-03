using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment2.Models;

namespace Assignment2.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            //ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            //ds.Configuration.LazyLoadingEnabled = false;

            // If necessary, add more constructor code here...

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

        public IEnumerable<EmployeeBase_vm> EmployeeGetAll()
        {
            return Mapper.Map<IEnumerable<Employee>, IEnumerable<EmployeeBase_vm>>(ds.Employees);
        }

        public EmployeeBase_vm EmployeeGetOne(int id)
        {
            var emp = ds.Employees.Find(id);

            if (emp == null)
            {
                return null;
            }
            else
            {
                return Mapper.Map<Employee, EmployeeBase_vm>(emp);
            }
        }

        public EmployeeBase_vm EmployeeAdd(EmployeeAdd_vm newOne)
        {
            var newEmp = ds.Employees.Add(Mapper.Map<EmployeeAdd_vm, Employee>(newOne));
            ds.SaveChanges();

            if (newEmp == null)
            {
                return null;
            }

            else
            {
                return Mapper.Map<Employee, EmployeeBase_vm>(newEmp);
            }
        }



    }
}