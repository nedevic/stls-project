scan-build \
-enable-checker security.FloatLoopCounter \
-enable-checker security.insecureAPI.DeprecatedOrUnsafeBufferHandling \
-enable-checker security.insecureAPI.bcmp \
-enable-checker security.insecureAPI.bcopy \
-enable-checker security.insecureAPI.bzero \
-enable-checker security.insecureAPI.rand \
-enable-checker security.insecureAPI.strcpy \
-enable-checker valist.CopyToSelf \
-enable-checker valist.Uninitialized \
-enable-checker valist.Unterminated \
-enable-checker nullability.NullableDereferenced \
-enable-checker nullability.NullablePassedToNonnull \
-enable-checker nullability.NullableReturnedFromNonnull \
-enable-checker optin.cplusplus.UninitializedObject \
-enable-checker optin.cplusplus.VirtualCall \
-enable-checker optin.mpi.MPI-Checker \
-enable-checker optin.osx.OSObjectCStyleCast \
-enable-checker optin.osx.cocoa.localizability.EmptyLocalizationContextChecker \
-enable-checker optin.osx.cocoa.localizability.NonLocalizedStringChecker \
-enable-checker optin.performance.GCDAntipattern \
-enable-checker optin.performance.Padding \
-enable-checker optin.portability.UnixAPI \
-maxloop 800 -o ./bin/results/ g++ main.cpp -o ./bin/a.out
