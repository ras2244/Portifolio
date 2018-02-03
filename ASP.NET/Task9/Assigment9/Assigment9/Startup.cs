using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Assigment9.Startup))]
namespace Assigment9
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
