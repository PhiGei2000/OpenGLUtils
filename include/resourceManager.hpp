#pragma once

#include <string>
#include <unordered_map>

namespace openGLUtils {
    enum class ResourceType
    {
        STRING,
        INTEGER,
        FLOAT,
        SHADER
    };

    struct Resource {
        std::string resourceId;
        ResourceType type;

        void* data;
    };

    class ResourceManager {
      private:
        std::unordered_map<std::string, Resource> resources;
        void setResource(const std::string& resourceId, ResourceType type, void* data);

      public:
        template<typename T>
        void setResource(const std::string& resourceId, const T& data);
        template<typename T>
        T* getResource(const std::string& resourceId) const;
    };
} // namespace openGLUtils