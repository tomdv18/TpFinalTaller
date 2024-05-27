#include "resolvererror.h"

<<<<<<< HEAD:src/common_src/resolvererror.cpp
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>

ResolverError::ResolverError(int gai_errno): gai_errno(gai_errno) {}

const char* ResolverError::what() const noexcept { return gai_strerror(gai_errno); }
=======
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

ResolverError::ResolverError(int gai_errno) : gai_errno(gai_errno) { }

const char* ResolverError::what() const noexcept {
    return gai_strerror(gai_errno);
}
>>>>>>> main:common_src/resolvererror.cpp

ResolverError::~ResolverError() {}
