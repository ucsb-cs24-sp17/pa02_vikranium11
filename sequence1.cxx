// sequence1.cxx - implements sequence1 class as defined in stats.h
// VIKRAM THARAKAN, 4/16/17

#include <cassert>  // provides assert
#include "sequence1.h"  // defines what must be implemented

namespace main_savitch_3
{
  const sequence::size_type sequence::CAPACITY;

  sequence::sequence(){
    used = 0;
  }
  
  void sequence::start(){
    current_index = 0;
  }

  void sequence::advance( ){
    current_index += 1;
  }
 
  void sequence::insert(const value_type& entry){
    size_type i;
    assert(size( ) < CAPACITY);
    if (!is_item( ))
      current_index = 0;
    for (i = used;i > current_index; --i)
      data[i] = data[i-1];
    data[current_index] = entry;
    ++used;

  }

  void sequence::attach(const value_type& entry){
    size_type i;
    assert(size( ) < CAPACITY);
    if (!is_item( )){
      current_index = used;
    }
    else{
      for (i = used;i > (current_index+1); --i)
	data[i] = data[i-1];
      current_index += 1;
    }
    data[current_index] = entry;
    used++;
  }

  void sequence::remove_current( ){
    assert(is_item() == true);
    size_type a = current_index;
    while(a < (used-1)){
      data[a] = data[a+1];
      a = a+1;
    }
    data[used-1] = 0;
    used -= 1;
  }


  bool sequence::is_item( ) const{
    if(current_index < used){
      return true;
    }
    else{
      return false;
    }
  }

  
  sequence::size_type sequence::size( ) const{
    return used;
  }
  
  sequence::value_type sequence::current( ) const{
    return data[current_index];
  }


}
