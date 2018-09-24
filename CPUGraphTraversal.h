#include "GraphTraversal.h"
#include "VertexStep.h"
#include "GraphStep.h"
#include "AddVertexStartStep.h"
#include "AddVertexStep.h"
#include "HasStep.h"
#include "Traverser.h"
#include <algorithm>

class CPUGraphTraversal : public GraphTraversal {
	public:
		CPUGraphTraversal(GraphTraversalSource* src)
		: GraphTraversal(src) {
			// do nothing
		}
		/**
			Processes the traversal if not already processed and returns the next traversal result.
		**/
		virtual void* next() {
			return NULL;
		}

		/**
			Processes the traversal if not already processed and executes the given function on
			each of the traversal results.
		**/
		virtual void forEachRemaining(std::function<void (void*)> func) {
			return;
		}

		/**
			Performs each step of the traversal.
		**/
		virtual void iterate() {
			std::vector<Traverser<void*>*> traversers; //TODO actually use these to traverse
			unsigned int index = 0;
			while(index < steps.size()) {
				switch(steps[index]->uid) {
					case GRAPH_STEP:
						{
							std::vector<Vertex*> vertices = getGraph()->vertices();
							for_each(vertices.begin(), vertices.end(), [](Vertex* v){printf("%llu\n", *((uint64_t*)v->id()));});
							// For each traverser, a traverser should be created for each Vertex and passed to the next step
							break;
						}
					case ADD_VERTEX_STEP:
						{
							// For each traverser ...
							((CPUGraph*)getGraph())->add_vertex();
							// For each traverser, a new Vertex should be created and replace the original traverser
							break;
						}
					case ADD_VERTEX_START_STEP:
						{
							((CPUGraph*)getGraph())->add_vertex();
						}
				}

				index++;
			}
		};
};