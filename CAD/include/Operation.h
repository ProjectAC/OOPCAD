#pragma once

namespace ACCAD
{
	class IOperation
	{
	public:
	   	/* Execute this operation
		 */
		virtual void exec() = 0;

		/* Undo this operation
		 */ 
		virtual void undo(std::ostream &out) = 0;
	};
}