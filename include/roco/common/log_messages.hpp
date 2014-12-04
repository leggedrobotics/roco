/**********************************************************************
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2014, Christian Gehring
 * All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Autonomous Systems Lab nor ETH Zurich
 *     nor the names of its contributors may be used to endorse or
 *     promote products derived from this software without specific
 *     prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */
/*!
* @file     log_messages.hpp
* @author   Christian Gehring
* @date     Dec, 2014
* @brief
*/
#pragma once

#include "roco/common/assert_macros.hpp"


namespace roco {
namespace common {

ROCO_DEFINE_EXCEPTION(roco_fatal, std::runtime_error)
ROCO_DEFINE_EXCEPTION(roco_error, std::runtime_error)


#define ROCO_FATAL(...) \
    std::stringstream roco_assert_stringstream;             \
    roco_assert_stringstream << roco::common::internal::roco_string_format(__VA_ARGS__); \
    roco::common::internal::roco_throw_exception<roco::common::roco_fatal>("[CTRL FATAL] ", __FUNCTION__,__FILE__,__LINE__, roco_assert_stringstream.str());

#define ROCO_FATAL_STREAM(message) \
    std::stringstream roco_assert_stringstream;             \
    roco_assert_stringstream << message; \
    roco::common::internal::roco_throw_exception<roco::common::roco_fatal>("[CTRL FATAL] ", __FUNCTION__,__FILE__,__LINE__, roco_assert_stringstream.str());

#define ROCO_ERROR(...) \
    std::stringstream roco_assert_stringstream;             \
    roco_assert_stringstream << roco::common::internal::roco_string_format(__VA_ARGS__); \
    roco::common::internal::roco_throw_exception<roco::common::roco_fatal>("[CTRL ERROR] ", __FUNCTION__,__FILE__,__LINE__, roco_assert_stringstream.str());

#define ROCO_ERROR_STREAM(message) \
    std::stringstream roco_assert_stringstream;             \
    roco_assert_stringstream << message; \
    roco::common::internal::roco_throw_exception<roco::common::roco_error>("[CTRL ERROR] ", __FUNCTION__,__FILE__,__LINE__, roco_assert_stringstream.str());

#define ROCO_INFO(...) \
    std::stringstream roco_stringstream; \
    roco::common::internal::source_file_pos sfp(__FUNCTION__,__FILE__,__LINE__); \
    roco_stringstream << "[CTRL INFO] " <<  sfp.toString() << " " << roco::common::internal::roco_string_format(__VA_ARGS__); \
    std::cout << roco_stringstream.str() << std::endl;

#define ROCO_INFO_STREAM(message) \
    std::stringstream roco_stringstream; \
    roco::common::internal::source_file_pos sfp(__FUNCTION__,__FILE__,__LINE__); \
    roco_stringstream << "[CTRL INFO] " <<  sfp.toString() << " " << message; \
    std::cout << roco_stringstream.str() << std::endl;

#define ROCO_WARN(...) \
    std::stringstream roco_stringstream; \
    roco::common::internal::source_file_pos sfp(__FUNCTION__,__FILE__,__LINE__); \
    roco_stringstream << "[CTRL WARN] " <<  sfp.toString() << " " << roco::common::internal::roco_string_format(__VA_ARGS__); \
    std::cout << roco_stringstream.str() << std::endl;

#define ROCO_WARN_STREAM(message) \
    std::stringstream roco_stringstream; \
    roco::common::internal::source_file_pos sfp(__FUNCTION__,__FILE__,__LINE__); \
    roco_stringstream << "[CTRL WARN] " <<  sfp.toString() << " " << message; \
    std::cout << roco_stringstream.str() << std::endl;


#ifndef NDEBUG
#define ROCO_DEBUG(...) \
    std::stringstream roco_stringstream; \
    roco::common::internal::source_file_pos sfp(__FUNCTION__,__FILE__,__LINE__); \
    roco_stringstream << "[CTRL DEBUG] " <<  sfp.toString() << " " << roco::common::internal::roco_string_format(__VA_ARGS__); \
    std::cout << roco_stringstream.str() << std::endl;

#define ROCO_DEBUG_STREAM(message) \
    std::stringstream roco_stringstream; \
    roco::common::internal::source_file_pos sfp(__FUNCTION__,__FILE__,__LINE__); \
    roco_stringstream << "[CTRL DEBUG] " <<  sfp.toString() << " " << message; \
    std::cout << roco_stringstream.str() << std::endl;
#else
#define ROCO_DEBUG(...)
#define ROCO_DEBUG_STREAM(message)
#endif

} // namespace common
} // namespace roco
