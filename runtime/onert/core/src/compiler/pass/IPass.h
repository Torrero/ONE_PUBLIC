/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ONERT_COMPILER_PASS_IPASS_H__
#define __ONERT_COMPILER_PASS_IPASS_H__

#include <string>

namespace onert::compiler::pass
{

struct IPass
{
  virtual ~IPass() = default;

  virtual std::string id() = 0;
  virtual void run() = 0;
};

} // namespace onert::compiler::pass

#endif // __ONERT_COMPILER_PASS_IPASS_H__
