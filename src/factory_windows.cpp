/*
** EPITECH PROJECT, 2019
** ZiaModuleAPISpec
** File description:
** Windows factory function example
*/

#include <memory>

#include "Zia/API.hpp"
//#include "MyModule.hpp"

__declspec(dllexport) Zia::API::Module::pointer factory()
{
    return std::make_shared<MyModule>();
}
