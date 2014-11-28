#include <libevm/VM.h>

#if ETH_EVMJIT
	#include<libevmjit/VM.h>
#endif

#include "VMFactory.h"

namespace dev
{
namespace eth
{

std::unique_ptr<VMFace> VMFactory::create(VMFactory::Kind _kind, u256 _gas)
{
#if ETH_EVMJIT
	auto vm = _kind == Kind::JIT ? static_cast<VMFace*>(new jit::VM)
								 : static_cast<VMFace*>(new VM);
#else
	VMFace* vm = new VM;
#endif

	vm->reset(_gas);
	return std::unique_ptr<VMFace>(vm);
}

}
}
