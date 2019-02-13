/*
** EPITECH PROJECT, 2019
** ZiaModuleAPISpec
** File description:
** Linux factory function example
*/

#include <memory>

#include "Zia/API.hpp"
#include "MyModule.hpp"

extern "C" Zia::API::Module::pointer factory()
{
    return std::make_shared<MyModule>();
}
