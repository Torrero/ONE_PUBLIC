/*
 * Copyright (c) 2025 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include "nnfw_tensorinfo_bindings.h"

#include "nnfw_api_wrapper.h"

namespace onert
{
namespace api
{
namespace python
{

namespace py = pybind11;

// Bind the `tensorinfo` class
void bind_tensorinfo(py::module_ &m)
{
  py::class_<tensorinfo>(m, "tensorinfo", "tensorinfo describes the type and shape of tensors",
                         py::module_local())
    .def(py::init<>(), "The constructor of tensorinfo")
    .def_readwrite("dtype", &tensorinfo::dtype, "The data type")
    .def_readwrite("rank", &tensorinfo::rank, "The number of dimensions (rank)")
    .def_property(
      "dims", [](const tensorinfo &ti) { return get_dims(ti); },
      [](tensorinfo &ti, const py::list &dims_list) { set_dims(ti, dims_list); },
      "The dimension of tensor. Maximum rank is 6 (NNFW_MAX_RANK).");
}

} // namespace python
} // namespace api
} // namespace onert