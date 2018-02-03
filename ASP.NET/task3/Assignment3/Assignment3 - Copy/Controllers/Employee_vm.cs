﻿using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class EmployeeBase
    {

        public EmployeeBase()
        {
            LastName = "";
            FirstName = "";
            Title = "";
            //Assume 25 years old
            DateTime current_date = DateTime.Now;
            BirthDate = current_date.AddYears(-25);
            HireDate = current_date;
            Address = "";
            City = "";
            State = "";
            Country = "";
            PostalCode = "";
            Phone = "";
            Fax = "";
            Email = "";
        }

        [Key]
        public int EmployeeId { get; set; }

        [Required]
        [StringLength(20)]
        [Display(Name = "Last Name")]
        public string LastName { get; set; }

        [Required]
        [StringLength(20)]
        [Display(Name = "First Name")]
        public string FirstName { get; set; }

        [StringLength(30)]
        public string Title { get; set; }
        [Display(Name = "Birth Date")]
        public DateTime? BirthDate { get; set; }

        [Display(Name = "Hire Date")]
        public DateTime? HireDate { get; set; }

        [StringLength(70)]
        public string Address { get; set; }

        [StringLength(40)]
        public string City { get; set; }

        [StringLength(40)]
        public string State { get; set; }

        [StringLength(40)]
        public string Country { get; set; }

        [Display(Name = "Postal Code")]
        [StringLength(10)]
        public string PostalCode { get; set; }

        [StringLength(24)]
        public string Phone { get; set; }

        [StringLength(24)]
        public string Fax { get; set; }

        [Display(Name = "Email Address")]
        [StringLength(60)]
        public string Email { get; set; }



    }
    public class EmployeeEditContactInfo
    {
        [Key]
        public int EmployeeId { get; set; }

        [StringLength(70)]
        public string Address { get; set; }

        [StringLength(40)]
        public string City { get; set; }

        [StringLength(40)]
        public string State { get; set; }

        [StringLength(40)]
        public string Country { get; set; }

        [Display(Name = "Postal Code")]
        [StringLength(10)]
        public string PostalCode { get; set; }

        [DataType(DataType.PhoneNumber)]
        [StringLength(24)]
        public string Phone { get; set; }

        [StringLength(24)]
        public string Fax { get; set; }

        [DataType(DataType.EmailAddress)]
        public string Email { get; set; }

        [DataType(DataType.Password)]
        public String Password { get; set; }

        [Display(Name = "Number of Weeks Vacation")]
        public int NumberOfWeeks { get; set; }
    }

    public class EmployeeEditContactInfoForm : EmployeeEditContactInfo
    {
        public EmployeeEditContactInfoForm()
        {

        }

        [Required]
        [StringLength(20)]
        [Display(Name = "Last Name")]
        public string LastName { get; set; }

        [Required]
        [StringLength(20)]
        [Display(Name = "First Name")]
        public string FirstName { get; set; }
    }
}