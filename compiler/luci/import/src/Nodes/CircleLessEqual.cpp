/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "luci/Import/Nodes/CircleLessEqual.h"

#include <luci/IR/Nodes/CircleLessEqual.h>

#include <loco.h>

namespace luci
{

bool CircleLessEqualGraphBuilder::validate(const ValidateArgs &args) const
{
  if (!GraphBuilder::validate(args, 2))
    return false;

  const auto &inputs = args.op.inputs;
  const auto &outputs = args.op.outputs;
  const auto tensors = args.reader.tensors();

  assert(tensors[inputs.at(0)] != nullptr && tensors[inputs.at(1)] != nullptr);
  if (tensors[inputs.at(0)]->type() != tensors[inputs.at(1)]->type())
  {
    return false;
  }

  assert(tensors[outputs[0]] != nullptr);
  return tensors[outputs[0]]->type() == circle::TensorType::TensorType_BOOL;
}

CircleNode *CircleLessEqualGraphBuilder::build_node(const circle::OperatorT &,
                                                    const std::vector<CircleNode *> &inputs,
                                                    loco::Graph *graph) const
{
  auto *node = graph->nodes()->create<CircleLessEqual>();
  node->x(inputs.at(0));
  node->y(inputs.at(1));

  return node;
}

} // namespace luci
