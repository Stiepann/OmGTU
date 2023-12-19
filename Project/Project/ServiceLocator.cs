using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project
{
    public class ServiceLocator
    {
        private static ServiceLocator locator = null;

        public static ServiceLocator Instance
        {
            get
            {
                // ServiceLocator itself is a Singleton
                if (locator == null)
                {
                    locator = new ServiceLocator();
                }
                return locator;
            }
        }

        private ServiceLocator()
        {

        }

        private Dictionary<string, object> registry = new Dictionary<string, object>();

        public void Register(string serviceName, object serviceInstance)
        {
            registry[serviceName] = serviceInstance;
        }

        public object GetService(string serviceName)
        {
            object serviceInstance = registry[serviceName];
            return serviceInstance;
        }
    }
}
