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

#include "HookResult.hpp"
#include "Request.hpp"
#include "Response.hpp"

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
    virtual ~RequestHandler();

    /*
     * CONNECTION HOOKS:
     *
     * onReadResponse:
     *     called when the server accepted the connection
     *     this hook should read the entiere request from the socket into the provided buffer.
     * onWriteResponse:
     *     called when the server has generated a response
     *     this hook should write the entiere response from the provided buffer into the socket
     */
    virtual HookResultType onReadRequest(boost::asio::ip::tcp::socket& sock, std::vector<char>& buf) { return HookResult::Declined; }
    virtual HookResultType onWriteResponse(boost::asio::ip::tcp::socket& sock, const std::vector<char>& buf) { return HookResult::Declined; }

    /*
     * REQUEST HOOKS:
     *
     * onPreRequest:
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
    virtual HookResultType onPreRequest(Request& req) { return HookResult::Declined; }
    virtual HookResultType onRequest(const Request& req, Response& res) { return HookResult::Declined; }
    virtual HookResultType onRequestError(int status, Response& res) { return HookResult::Declined; }
    virtual HookResultType onResponse(Response& res) { return HookResult::Declined; }
};

}
}
