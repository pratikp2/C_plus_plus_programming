#include <iostream>
using namespace std;






// 1. []{}();  simplest lambda function.
// 2. Lambda function are defined inside the body of the another function.
// 3. By default local variable declared inside the outer finction can not be used directly inside the lambda function.
// 4. To use the local variables out side the lambda body entry of those variables must be made in the capture list.
// 5. By default the Variables out side the lambda body are read only, so to change the outside variables reference of
//    those variables has to be passed.
// 6. If we put equal in hte capture list [=], then we don't have to mention every varible outside the lambda body in the
//    capture list. Still it will be pass by value hence read only.
// 7. To render write options pass & in the square brackets [&] i,e. capture bt reference. And suppose if we have to restrict
//    the write access to some variables then simply mention them in the capture list next to & by putting , i.e, [&, i]
//    Similarly [=, &i].
