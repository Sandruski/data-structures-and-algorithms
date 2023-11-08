#pragma once

#include "GraphSearchAlgorithms/Helpers/GraphFwd.h"
#include "GraphSearchAlgorithms/Helpers/PathfindingListFwd.h"

namespace GraphSearchAlgorithms
{
Path BuildPath(const NodeRecord& inCurrentNodeRecord, const PathfindingList& inClosedList, const Node inStartNode, const Node inGoalNode);
} // namespace GraphSearchAlgorithms
