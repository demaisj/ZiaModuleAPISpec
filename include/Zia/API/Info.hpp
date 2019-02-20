/*
** EPITECH PROJECT, 2019
** ZiaModuleAPISpec
** File description:
** Info spec
*/

#pragma once

#include <string>
#include <chrono>

namespace Zia {
namespace API {

/*
 * INFO OBJECT
 *
 * Contains all the informations about the current client connection.
 */
struct Info {

    /*
     * Client ip
     */
    std::string ip;

    /*
     * Client port:
     */
    std::uint16_t port;

    /*
     * Server up time:
     *     Time elapsed since start of the server.
     */
	std::chrono::system_clock::duration serverUpTime;

	/*
     * Request process time:
     *     The time elapsed after process a request.
     */
	std::chrono::system_clock::duration requestProcessTime;
};

}
}