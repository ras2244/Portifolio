### Week 2 code examples

**GetAllGetOne**

Use the "get all" and "get one" tasks, in an app that uses a persistent store.  

Features:
- based on the "Web app project v1" project template
- persistent store
- implements "get all" and "get one" tasks

**AddNew**

Has the features of the "GetAllGetOne" code example, and adds the "add new" pattern for a new object.  

Features:
- functionality is based on the "GetAllGetOne" app above
- implements the "add new" task
- introduces some important concepts; model validation, view model class inheritance, PRG pattern, etc.

**AddNew-usingAutoMapperStaticAPI**

This is the only example that uses AutoMapper Static API. You're not allowed to use static API in any assignment.

Here is simple instruction for the AutoMapper static API in this example:
- AutoMapper mappings are created in the file AutoMapperConfig.cs under the App_Start folder
- The AutoMapperConfig class is initialed Global.asax's Application_Start() method
- The created mappings are used with the static methods, e.g. Mapper.Map<Customer, CustomerBase>(addedItem);

 