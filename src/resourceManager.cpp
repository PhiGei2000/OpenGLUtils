#include "resourceManager.hpp"
#include "shader.hpp"

#include <stdexcept>

namespace openGLUtils {
    void ResourceManager::setResource(const std::string& resourceId, ResourceType type, void* data) {
        Resource res = Resource{
            resourceId, type, data};

        resources[resourceId] = res;
    }

    template<>
    void ResourceManager::setResource(const std::string& resourceId, const std::string& str) {
        std::string* resource = new std::string(str);

        setResource(resourceId, ResourceType::STRING, resource);
    }

    template<>
    void ResourceManager::setResource(const std::string& resourceId, const int& value) {
        int* resource = new int(value);

        setResource(resourceId, ResourceType::INTEGER, resource);
    }

    template<>
    void ResourceManager::setResource(const std::string& resourceId, const float& value) {
        float* resource = new float(value);

        setResource(resourceId, ResourceType::FLOAT, resource);
    }

    template<>
    void ResourceManager::setResource(const std::string& resourceId, const Shader& shader) {
        Shader* resource = new Shader(shader);

        setResource(resourceId, ResourceType::SHADER, resource);
    }

    template<>
    std::string* ResourceManager::getResource(const std::string& resourceId) const {
        const Resource& res = resources.at(resourceId);

        if (res.type != ResourceType::STRING) {
            throw std::invalid_argument("Resource could not converted to a string");
        }

        return reinterpret_cast<std::string*>(res.data);
    }

    template<>
    int* ResourceManager::getResource(const std::string& resourceId) const {
        const Resource& res = resources.at(resourceId);

        if (res.type != ResourceType::INTEGER) {
            throw std::invalid_argument("Resource could not converted to an integer");
        }

        return reinterpret_cast<int*>(res.data);
    }

    template<>
    float* ResourceManager::getResource(const std::string& resourceId) const {
        const Resource& res = resources.at(resourceId);

        if (res.type != ResourceType::FLOAT) {
            throw std::invalid_argument("Resource could not converted to a float");
        }

        return reinterpret_cast<float*>(res.data);
    }

    template<>
    Shader* ResourceManager::getResource(const std::string& resourceId) const {
        const Resource& res = resources.at(resourceId);

        if (res.type != ResourceType::SHADER) {
            throw std::invalid_argument("Resource could not converted to a shader");
        }

        return reinterpret_cast<Shader*>(res.data);
    }

} // namespace openGLUtils