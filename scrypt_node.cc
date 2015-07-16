/*
	scrypt_node.cc

	Copyright (C) 2013 Barry Steyn (http://doctrina.org/Scrypt-Authentication-For-Node.html)

	This source code is provided 'as-is', without any express or implied
	warranty. In no event will the author be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this source code must not be misrepresented; you must not
	claim that you wrote the original source code. If you use this source code
	in a product, an acknowledgment in the product documentation would be
	appreciated but is not required.

	2. Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original source code.

	3. This notice may not be removed or altered from any source distribution.

	Barry Steyn barry.steyn@gmail.com

*/
#include <node.h>
#include <nan.h>
#include <v8.h>

using namespace v8;
//#include "src/node-boilerplate/scrypt_kdf.h"
//#include "src/node-boilerplate/scrypt_hash.h"
//#include "src/node-boilerplate/scrypt_verify.h"
//#include "src/node-boilerplate/scrypt_params.h"
//#include "src/node-boilerplate/scrypt_error.h"

//
// Forward declarations
//
NAN_METHOD(ParamsSync);
NAN_METHOD(Params);
NAN_METHOD(KDFSync);

//
// Module initialisation function
//
void RegisterModule(Handle<Object> target) {

	//Params (Translation function)
	target->Set(NanNew<String>("ParamsSync"),
		NanNew<FunctionTemplate>(ParamsSync)->GetFunction());

	target->Set(NanNew<String>("Params"),
		NanNew<FunctionTemplate>(Params)->GetFunction());

	target->Set(NanNew<String>("KDFSync"),
		NanNew<FunctionTemplate>(KDFSync)->GetFunction());

/*
	//KDF
	target->Set(NanNew<String>("KDF"),
		NanNew<FunctionTemplate>(CreateKeyDerivationFunction)->GetFunction());

	//Hash function
	target->Set(NanNew<String>("Hash"),
		NanNew<FunctionTemplate>(CreateHashFunction)->GetFunction());

	//Verify hash
	target->Set(NanNew<String>("Verify"),
		NanNew<FunctionTemplate>(CreateVerifyFunction)->GetFunction());

	//Error Object
	target->Set(NanNew<String>("errorObject"),
		NanNew<FunctionTemplate>(MakeErrorObject)->GetFunction());
*/
}

NODE_MODULE(scrypt, RegisterModule)
