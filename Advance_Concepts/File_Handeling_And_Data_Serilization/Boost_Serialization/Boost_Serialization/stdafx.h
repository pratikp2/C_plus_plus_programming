#pragma once

#include <iostream>
#include <vector>  
#include <fstream>   
#include <string>
#include <memory>

#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <boost/serialization/vector.hpp> 
#include <boost/serialization/version.hpp>
#include <boost/serialization/binary_object.hpp>