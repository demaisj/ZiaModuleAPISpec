/*
** EPITECH PROJECT, 2019
** ZiaModuleAPISpec
** File description:
** Request handler spec
*/

#pragma once

#include <memory>
#include <vector>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

#include "HookResult.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Connection.hpp"

namespace Zia {
namespace API {

/*
 * REQUEST HANDLER
 *
 * This class is instantiated for each request, and provides hooks to
 * handle incoming requests.
 *
 * Use exceptions for critial errors in the module code. Those can be catched
 * by the server in order to shut down the module and prevent a crash.
 */
class RequestHandler {
public:
    using pointer = std::shared_ptr<RequestHandler>;

    /*
     * INSTANTIATION:
     *
     * constructor:
     *     used to allocated needed resources for said request handler.
     *     a reference of the module instance can be passed by the module
     *     (in the newRequestHanlder method) to maintain access to module
     *     resources, etc.
     * destructor:
     *     used to deallocate those same resources
     */
    virtual ~RequestHandler() {};

    /*
     * CONNECTION HOOKS:
     *
     * onConnectionRead:
     *     called when the server accepted the connection
     *     this hook should read the entiere request from the socket into the provided buffer.
     * onConnectionWrite:
     *     called when the server has generated a response
     *     this hook should write the entiere response from the provided buffer into the socket
     */
    virtual HookResultType onConnectionStart(const Connection& conn, tcp::socket& sock) { return HookResult::Declined; }
    virtual HookResultType onConnectionEnd(const Connection& conn, tcp::socket& sock) { return HookResult::Declined; }
    virtual HookResultType onConnectionRead(const Connection& conn, tcp::socket& sock, std::vector<char>& buf, size_t& read) { return HookResult::Declined; }
    virtual HookResultType onConnectionWrite(const Connection& conn, tcp::socket& sock, const std::vector<char>& buf, size_t& written) { return HookResult::Declined; }

    /*
     * REQUEST HOOKS:
     *
     * onBeforeRequest:
     *     called before calling onRequest
     *     can be used to alter the incoming request before processing it
     * onRequest:
     *     this hook process the request and generates a response
     * onRequestError:
     *     this hook is called if a previous hook returned with a HTTP error code
     *     it should generate the error response.
     * onResponse:
     *     called after calling onRequest
     *     can be used to alter the outgoing response before sending it
     */
    virtual HookResultType onBeforeRequest(const Connection& conn, Request& req) { return HookResult::Declined; }
    virtual HookResultType onRequest(const Connection& conn, const Request& req, Response& res) { return HookResult::Declined; }
    virtual HookResultType onRequestError(const Connection& conn, int status, Response& res) { return HookResult::Declined; }
    virtual HookResultType onResponse(const Connection& conn, Response& res) { return HookResult::Declined; }
};

}
}
