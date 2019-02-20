/*
** EPITECH PROJECT, 2019
** ZiaModuleAPISpec
** File description:
** Server config spec
*/

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#include <boost/variant.hpp>
#pragma GCC diagnostic pop

#include <string>
#include <vector>
#include <map>
#include <unordered_map> // Should be removed

#include "Definitions.hpp"

namespace Zia {
namespace API {

/*
 * SERVER CONFIGURATION:
 *
 * This struct contains all configuration needed to initialize a module.
 * The user-provided config is transmitted in a string map.
 */
struct ServerConfig {

    enum class Platform {
        Linux,
        Windows,
        Macos
    };

    /*
     * Server name:
     *     can be set to system's hostname
     */
    std::string name;

    /*
     * Server version:
     *     can be used to require specific version from module
     */
    std::string version;

    /*
     * Server platform:
     *     which platform the server is running on
     */
    Platform platform;

    /*
     * Represents a json null value
     */
    struct Null {};

    /*
     * Server config:
     *     Represents any json value
     */
    using Value = boost::make_recursive_variant<std::string,
												int,
												double,
												bool,
												std::map<std::string, boost::recursive_variant_>,
												std::vector<boost::recursive_variant_>,
												Null>::type;

    /*
     * Represents a json array
     */
    using Array = std::vector<Value>;

    /*
     * Represents a json object
     */
    using Object = std::map<std::string, Value>;

    /*
     * Holds the configuration
     */
    Value config;

    /*
     * API spec version:
     *     Do not touch this, it is already set by default.
     */
    std::string apispec_version = Definitions::VERSION;
};

}
}
