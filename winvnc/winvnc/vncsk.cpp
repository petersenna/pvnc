// This file is generated by omniidl (C++ backend)- omniORB_3_0. Do not edit.

#include "vnc.hh"
#include <omniORB3/callDescriptor.h>

static const char* _0RL_library_version = omniORB_3_0;

_init_in_def_( const CORBA::Short vnc::protocolMajorVersion = 3; )

_init_in_def_( const CORBA::UShort vnc::FLASHPORT = 5400; )

_init_in_def_( const CORBA::UShort vnc::CLIENTPORT = 400; )

_init_in_def_( const CORBA::UShort vnc::SERVERPORT = 5900; )

_init_in_def_( const CORBA::UShort vnc::DISPLAY_DEVICE = 1; )

_init_in_def_( const CORBA::UShort vnc::KEYBOARD_DEVICE = 2; )

_init_in_def_( const CORBA::UShort vnc::POINTER_DEVICE = 4; )

_init_in_def_( const CORBA::UShort vnc::ALL_DEVICES = 7; )

CORBA::Exception::insertExceptionToAny vnc::connectionFailed::insertToAnyFn = 0;
CORBA::Exception::insertExceptionToAnyNCP vnc::connectionFailed::insertToAnyFnNCP = 0;

vnc::connectionFailed::connectionFailed(const vnc::connectionFailed& _s) : CORBA::UserException(_s)
{
  
}

vnc::connectionFailed& vnc::connectionFailed::operator=(const vnc::connectionFailed& _s)
{
  ((CORBA::UserException*) this)->operator=(_s);
  
  return *this;
}

vnc::connectionFailed::~connectionFailed() {}

void vnc::connectionFailed::_raise() { throw *this; }

vnc::connectionFailed* vnc::connectionFailed::_downcast(CORBA::Exception* _e) {
  return (connectionFailed*) _NP_is_a(_e, "Exception/UserException/vnc::connectionFailed");
}

const vnc::connectionFailed* vnc::connectionFailed::_downcast(const CORBA::Exception* _e) {
  return (const connectionFailed*) _NP_is_a(_e, "Exception/UserException/vnc::connectionFailed");
}

const char* vnc::connectionFailed::_PD_repoId = "IDL:vnc/connectionFailed:1.0";

CORBA::Exception* vnc::connectionFailed::_NP_duplicate() const {
  return new connectionFailed(*this);
}

const char* vnc::connectionFailed::_NP_typeId() const {
  return "Exception/UserException/vnc::connectionFailed";
}

const char* vnc::connectionFailed::_NP_repoId(int* _size) const {
  *_size = sizeof("IDL:vnc/connectionFailed:1.0");
  return "IDL:vnc/connectionFailed:1.0";
}

void vnc::connectionFailed::_NP_marshal(NetBufferedStream& _s) const {
  *this >>= _s;
}

void vnc::connectionFailed::_NP_marshal(MemBufferedStream& _s) const {
  *this >>= _s;
}

size_t
vnc::clientInfo::_NP_alignedSize(size_t _initialoffset) const
{
  CORBA::ULong _msgsize = _initialoffset;
  _msgsize = omni::align_to(_msgsize, omni::ALIGN_2) + 2;

  _msgsize = clientAddress._NP_alignedSize(_msgsize);

  _msgsize = omni::align_to(_msgsize, omni::ALIGN_2) + 2;

  _msgsize += 1;

  _msgsize += 1;

  _msgsize += 1;

  _msgsize += 1;

  return _msgsize;
}

void
vnc::clientInfo::operator>>= (NetBufferedStream &_n) const
{
  clientId >>= _n;
  clientAddress >>= _n;
  capabilities >>= _n;
  isTeleport >>= _n;
  pointerEnabled >>= _n;
  keyboardEnabled >>= _n;
  closePending >>= _n;
  
}

void
vnc::clientInfo::operator<<= (NetBufferedStream &_n)
{
  clientId <<= _n;
  clientAddress <<= _n;
  capabilities <<= _n;
  isTeleport <<= _n;
  pointerEnabled <<= _n;
  keyboardEnabled <<= _n;
  closePending <<= _n;
  
}

void
vnc::clientInfo::operator>>= (MemBufferedStream &_n) const
{
  clientId >>= _n;
  clientAddress >>= _n;
  capabilities >>= _n;
  isTeleport >>= _n;
  pointerEnabled >>= _n;
  keyboardEnabled >>= _n;
  closePending >>= _n;
  
}

void
vnc::clientInfo::operator<<= (MemBufferedStream &_n)
{
  clientId <<= _n;
  clientAddress <<= _n;
  capabilities <<= _n;
  isTeleport <<= _n;
  pointerEnabled <<= _n;
  keyboardEnabled <<= _n;
  closePending <<= _n;
  
}

vnc::controller_ptr vnc::controller_Helper::_nil() {
  return vnc::controller::_nil();
}

CORBA::Boolean vnc::controller_Helper::is_nil(vnc::controller_ptr p) {
  return CORBA::is_nil(p);

}

void vnc::controller_Helper::release(vnc::controller_ptr p) {
  CORBA::release(p);
}

void vnc::controller_Helper::duplicate(vnc::controller_ptr p) {
  if( p && !p->_NP_is_nil() )  omni::duplicateObjRef(p);
}

size_t vnc::controller_Helper::NP_alignedSize(vnc::controller_ptr obj, size_t offset) {
  return vnc::controller::_alignedSize(obj, offset);
}

void vnc::controller_Helper::marshalObjRef(vnc::controller_ptr obj, NetBufferedStream& s) {
  vnc::controller::_marshalObjRef(obj, s);
}

vnc::controller_ptr vnc::controller_Helper::unmarshalObjRef(NetBufferedStream& s) {
  return vnc::controller::_unmarshalObjRef(s);
}

void vnc::controller_Helper::marshalObjRef(vnc::controller_ptr obj, MemBufferedStream& s) {
  vnc::controller::_marshalObjRef(obj, s);
}

vnc::controller_ptr vnc::controller_Helper::unmarshalObjRef(MemBufferedStream& s) {
  return vnc::controller::_unmarshalObjRef(s);
}

vnc::controller_ptr
vnc::controller::_duplicate(vnc::controller_ptr obj)
{
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);

  return obj;
}

vnc::controller_ptr
vnc::controller::_narrow(CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}

vnc::controller_ptr
vnc::controller::_nil()
{
  static _objref_controller* _the_nil_ptr = 0;
  if( !_the_nil_ptr ) {
    omni::nilRefLock().lock();
  if( !_the_nil_ptr )  _the_nil_ptr = new _objref_controller;
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
}

const char* vnc::controller::_PD_repoId = "IDL:vnc/controller:1.0";

vnc::_objref_controller::~_objref_controller() {}

vnc::_objref_controller::_objref_controller(const char* mdri,
   IOP::TaggedProfileList* p, omniIdentity* id, omniLocalIdentity* lid) :
   
   omniObjRef(vnc::controller::_PD_repoId, mdri, p, id, lid)
{
  _PR_setobj(this);
}

void*
vnc::_objref_controller::_ptrToObjRef(const char* id)
{
  if( !strcmp(id, CORBA::Object::_PD_repoId) )
    return (CORBA::Object_ptr) this;
  if( !strcmp(id, vnc::controller::_PD_repoId) )
    return (vnc::controller_ptr) this;
  
  return 0;
}

// Proxy call descriptor class. Mangled signature:
//  void_o_cstring_o_cunsigned_pshort
class _0RL_cd_22cbff1b827fd898_00000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_22cbff1b827fd898_00000000(LocalCallFn lcfn, const char* op, size_t oplen, _CORBA_Boolean oneway, char *& a_0, CORBA::UShort& a_1):
     omniCallDescriptor(lcfn, op, oplen, oneway),
     arg_0(a_0),
     arg_1(a_1) {}

  virtual void unmarshalReturnedValues(GIOP_C&);
    
  char *& arg_0;
  CORBA::UShort& arg_1;
  
};

void _0RL_cd_22cbff1b827fd898_00000000::unmarshalReturnedValues(GIOP_C& giop_client)
{
  char* tmp_0 = 0;
  
  {
    CORBA::String_member _0RL_str_tmp;
    _0RL_str_tmp <<=  giop_client;
    tmp_0 = _0RL_str_tmp._ptr;
    _0RL_str_tmp._ptr = 0;
  }
  arg_1 <<= giop_client;
  
  arg_0 = tmp_0;
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_10000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_00000000* tcd = (_0RL_cd_22cbff1b827fd898_00000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  impl->getServerAddress(tcd->arg_0, tcd->arg_1);
}

void vnc::_objref_controller::getServerAddress(CORBA::String_out address, CORBA::UShort& port)
{
  _0RL_cd_22cbff1b827fd898_00000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_10000000, "getServerAddress", 17, 0, address, port);
  
  _invoke(_call_desc);
  
}

// Proxy call descriptor class. Mangled signature:
//  void_o_cunsigned_pshort_o_cunsigned_pshort_o_cunsigned_pshort
class _0RL_cd_22cbff1b827fd898_20000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_22cbff1b827fd898_20000000(LocalCallFn lcfn, const char* op, size_t oplen, _CORBA_Boolean oneway, CORBA::UShort& a_0, CORBA::UShort& a_1, CORBA::UShort& a_2):
     omniCallDescriptor(lcfn, op, oplen, oneway),
     arg_0(a_0),
     arg_1(a_1),
     arg_2(a_2) {}

  virtual void unmarshalReturnedValues(GIOP_C&);
    
  CORBA::UShort& arg_0;
  CORBA::UShort& arg_1;
  CORBA::UShort& arg_2;
  
};

void _0RL_cd_22cbff1b827fd898_20000000::unmarshalReturnedValues(GIOP_C& giop_client)
{
  
  arg_0 <<= giop_client;
  arg_1 <<= giop_client;
  arg_2 <<= giop_client;
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_30000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_20000000* tcd = (_0RL_cd_22cbff1b827fd898_20000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  impl->getDesktopSize(tcd->arg_0, tcd->arg_1, tcd->arg_2);
}

void vnc::_objref_controller::getDesktopSize(CORBA::UShort& width, CORBA::UShort& height, CORBA::UShort& depth)
{
  _0RL_cd_22cbff1b827fd898_20000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_30000000, "getDesktopSize", 15, 0, width, height, depth);
  
  _invoke(_call_desc);
  
}

// Proxy call descriptor class. Mangled signature:
//  _cunsigned_pshort_i_cstring_i_cunsigned_pshort_i_cunsigned_pshort_i_cboolean_i_cboolean_e_cvnc_mconnectionFailed
class _0RL_cd_22cbff1b827fd898_40000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_22cbff1b827fd898_40000000(LocalCallFn lcfn, const char* op, size_t oplen, _CORBA_Boolean oneway, const char* a_0, CORBA::UShort a_1, CORBA::UShort a_2, CORBA::Boolean a_3, CORBA::Boolean a_4):
     omniCallDescriptor(lcfn, op, oplen, oneway),
     arg_0(a_0),
     arg_1(a_1),
     arg_2(a_2),
     arg_3(a_3),
     arg_4(a_4) {}

  virtual CORBA::ULong alignedSize(CORBA::ULong size_in);
  virtual void marshalArguments(GIOP_C&);
  
  virtual void unmarshalReturnedValues(GIOP_C&);
    
  virtual void userException(GIOP_C&, const char*);
  
  inline CORBA::UShort result() { return pd_result; }
  const char* arg_0;
  CORBA::UShort arg_1;
  CORBA::UShort arg_2;
  CORBA::Boolean arg_3;
  CORBA::Boolean arg_4;
  CORBA::UShort pd_result;
};

CORBA::ULong _0RL_cd_22cbff1b827fd898_40000000::alignedSize(CORBA::ULong msgsize)
{
  msgsize = omni::align_to(msgsize, omni::ALIGN_4) + 4;
  msgsize += ((const char*) arg_0) ? strlen((const char*) arg_0) + 1 : 1;
  
  msgsize = omni::align_to(msgsize, omni::ALIGN_2) + 2;
  
  msgsize = omni::align_to(msgsize, omni::ALIGN_2) + 2;
  
  msgsize += 1;
  
  msgsize += 1;
  
  return msgsize;
}

void _0RL_cd_22cbff1b827fd898_40000000::marshalArguments(GIOP_C& giop_client)
{
  {
    CORBA::ULong _len = (((const char*) arg_0)? strlen((const char*) arg_0) + 1 : 1);
    
    _len >>= giop_client;
    if (_len > 1)
      giop_client.put_char_array((const CORBA::Char *)((const char*)arg_0),_len);
    else {
      if ((const char*) arg_0 == 0 && omniORB::traceLevel > 1)
        _CORBA_null_string_ptr(0);
      CORBA::Char('\0') >>= giop_client;
    }
  }
  arg_1 >>= giop_client;
  arg_2 >>= giop_client;
  arg_3 >>= giop_client;
  arg_4 >>= giop_client;
  
}

void _0RL_cd_22cbff1b827fd898_40000000::unmarshalReturnedValues(GIOP_C& giop_client)
{
  
  pd_result <<= giop_client;
  
}

void _0RL_cd_22cbff1b827fd898_40000000::userException(GIOP_C& giop_client, const char* repoId)
{
  if( strcmp(repoId, vnc::connectionFailed::_PD_repoId) == 0 ) {
    vnc::connectionFailed _ex;
    _ex <<= giop_client;
    giop_client.RequestCompleted();
    throw _ex;
  }
  
  else {
    giop_client.RequestCompleted(1);
    throw CORBA::MARSHAL(0, CORBA::COMPLETED_MAYBE);
  }
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_50000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_40000000* tcd = (_0RL_cd_22cbff1b827fd898_40000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  tcd->pd_result = impl->initiateConnection(tcd->arg_0, tcd->arg_1, tcd->arg_2, tcd->arg_3, tcd->arg_4);
}

CORBA::UShort vnc::_objref_controller::initiateConnection(const char* clientAddress, CORBA::UShort port, CORBA::UShort capability, CORBA::Boolean enableInputs, CORBA::Boolean isTeleport)
{
  _0RL_cd_22cbff1b827fd898_40000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_50000000, "initiateConnection", 19, 0, clientAddress, port, capability, enableInputs, isTeleport);
  
  _invoke(_call_desc);
  return _call_desc.result();
}

// Proxy call descriptor class. Mangled signature:
//  void_i_cunsigned_pshort
class _0RL_cd_22cbff1b827fd898_60000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_22cbff1b827fd898_60000000(LocalCallFn lcfn, const char* op, size_t oplen, _CORBA_Boolean oneway, CORBA::UShort a_0):
     omniCallDescriptor(lcfn, op, oplen, oneway),
     arg_0(a_0) {}

  virtual CORBA::ULong alignedSize(CORBA::ULong size_in);
  virtual void marshalArguments(GIOP_C&);
  
  CORBA::UShort arg_0;
  
};

CORBA::ULong _0RL_cd_22cbff1b827fd898_60000000::alignedSize(CORBA::ULong msgsize)
{
  msgsize = omni::align_to(msgsize, omni::ALIGN_2) + 2;
  
  return msgsize;
}

void _0RL_cd_22cbff1b827fd898_60000000::marshalArguments(GIOP_C& giop_client)
{
  arg_0 >>= giop_client;
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_70000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_60000000* tcd = (_0RL_cd_22cbff1b827fd898_60000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  impl->closeConnection(tcd->arg_0);
}

void vnc::_objref_controller::closeConnection(CORBA::UShort connectionId)
{
  _0RL_cd_22cbff1b827fd898_60000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_70000000, "closeConnection", 16, 1/*oneway*/, connectionId);
  
  _invoke(_call_desc);
  
}

// Proxy call descriptor class. Mangled signature:
//  _cunsigned_plong
class _0RL_cd_22cbff1b827fd898_80000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_22cbff1b827fd898_80000000(LocalCallFn lcfn, const char* op, size_t oplen, _CORBA_Boolean oneway):
     omniCallDescriptor(lcfn, op, oplen, oneway) {}

  virtual void unmarshalReturnedValues(GIOP_C&);
    
  inline CORBA::ULong result() { return pd_result; }
  
  CORBA::ULong pd_result;
};

void _0RL_cd_22cbff1b827fd898_80000000::unmarshalReturnedValues(GIOP_C& giop_client)
{
  
  pd_result <<= giop_client;
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_90000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_80000000* tcd = (_0RL_cd_22cbff1b827fd898_80000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  tcd->pd_result = impl->getTimeSinceLastConnection();
}

CORBA::ULong vnc::_objref_controller::getTimeSinceLastConnection()
{
  _0RL_cd_22cbff1b827fd898_80000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_90000000, "getTimeSinceLastConnection", 27, 0);
  
  _invoke(_call_desc);
  return _call_desc.result();
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_a0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  impl->shutdown();
}

void vnc::_objref_controller::shutdown()
{
  omniStdCallDesc::void_call _call_desc(_0RL_lcfn_22cbff1b827fd898_a0000000, "shutdown", 9, 1/*oneway*/);
  
  _invoke(_call_desc);
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_b0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_60000000* tcd = (_0RL_cd_22cbff1b827fd898_60000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  impl->enableKeyboardDevice(tcd->arg_0);
}

void vnc::_objref_controller::enableKeyboardDevice(CORBA::UShort periperalId)
{
  _0RL_cd_22cbff1b827fd898_60000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_b0000000, "enableKeyboardDevice", 21, 1/*oneway*/, periperalId);
  
  _invoke(_call_desc);
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_c0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_60000000* tcd = (_0RL_cd_22cbff1b827fd898_60000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  impl->disableKeyboardDevice(tcd->arg_0);
}

void vnc::_objref_controller::disableKeyboardDevice(CORBA::UShort peripheralId)
{
  _0RL_cd_22cbff1b827fd898_60000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_c0000000, "disableKeyboardDevice", 22, 1/*oneway*/, peripheralId);
  
  _invoke(_call_desc);
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_d0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_60000000* tcd = (_0RL_cd_22cbff1b827fd898_60000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  impl->enablePointerDevice(tcd->arg_0);
}

void vnc::_objref_controller::enablePointerDevice(CORBA::UShort periperalId)
{
  _0RL_cd_22cbff1b827fd898_60000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_d0000000, "enablePointerDevice", 20, 1/*oneway*/, periperalId);
  
  _invoke(_call_desc);
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_e0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_60000000* tcd = (_0RL_cd_22cbff1b827fd898_60000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  impl->disablePointerDevice(tcd->arg_0);
}

void vnc::_objref_controller::disablePointerDevice(CORBA::UShort peripheralId)
{
  _0RL_cd_22cbff1b827fd898_60000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_e0000000, "disablePointerDevice", 21, 1/*oneway*/, peripheralId);
  
  _invoke(_call_desc);
  
}

// Proxy call descriptor class. Mangled signature:
//  _cvnc_mclientInfoList
class _0RL_cd_22cbff1b827fd898_f0000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_22cbff1b827fd898_f0000000(LocalCallFn lcfn, const char* op, size_t oplen, _CORBA_Boolean oneway):
     omniCallDescriptor(lcfn, op, oplen, oneway) {}

  virtual void unmarshalReturnedValues(GIOP_C&);
    
  inline vnc::clientInfoList* result() { return pd_result; }
  
  vnc::clientInfoList* pd_result;
  
};

void _0RL_cd_22cbff1b827fd898_f0000000::unmarshalReturnedValues(GIOP_C& giop_client)
{
  
  pd_result = new vnc::clientInfoList;
  *pd_result <<= giop_client;
  
}

// Proxy call descriptor class. Mangled signature:
//  void_i_cvnc_mclientInfoList
class _0RL_cd_22cbff1b827fd898_01000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_22cbff1b827fd898_01000000(LocalCallFn lcfn, const char* op, size_t oplen, _CORBA_Boolean oneway, const vnc::clientInfoList& a_0):
     omniCallDescriptor(lcfn, op, oplen, oneway),
     arg_0(a_0) {}

  virtual CORBA::ULong alignedSize(CORBA::ULong);
  virtual void marshalArguments(GIOP_C&);
  
  const vnc::clientInfoList& arg_0;
  
};

CORBA::ULong _0RL_cd_22cbff1b827fd898_01000000::alignedSize(CORBA::ULong msgsize)
{
  msgsize = arg_0._NP_alignedSize(msgsize);
  
  return msgsize;
}

void _0RL_cd_22cbff1b827fd898_01000000::marshalArguments(GIOP_C& giop_client)
{
  arg_0 >>= giop_client;
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_11000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_f0000000* tcd = (_0RL_cd_22cbff1b827fd898_f0000000*) cd;
  vnc::_impl_controller* impl = (vnc::_impl_controller*) svnt->_ptrToInterface(vnc::controller::_PD_repoId);
  tcd->pd_result = impl->clientList();
}

vnc::clientInfoList* vnc::_objref_controller::clientList()
{
  _0RL_cd_22cbff1b827fd898_f0000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_11000000, "_get_clientList", 16, 0);
  
  _invoke(_call_desc);
  return _call_desc.result();
}

vnc::_pof_controller::~_pof_controller() {}

omniObjRef*
vnc::_pof_controller::newObjRef(const char* mdri, IOP::TaggedProfileList* p,
               omniIdentity* id, omniLocalIdentity* lid)
{
  return new vnc::_objref_controller(mdri, p, id, lid);
}

CORBA::Boolean
vnc::_pof_controller::is_a(const char* id) const
{
  if( !strcmp(id, vnc::controller::_PD_repoId) )
    return 1;
  
  return 0;
}

const vnc::_pof_controller _the_pof_vnc_mcontroller;

vnc::_impl_controller::~_impl_controller() {}

CORBA::Boolean
vnc::_impl_controller::_dispatch(GIOP_S& giop_s)
{
  if( !strcmp(giop_s.operation(), "_get_clientList") ) {    
    giop_s.RequestReceived();
    clientInfoList_var result = this->clientList();
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      msgsize = (result.operator->())->_NP_alignedSize(msgsize);
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      *(result.operator->()) >>= giop_s;
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "getServerAddress") ) {
    
    CORBA::String_var arg_address;
    
    CORBA::UShort arg_port;
    
    giop_s.RequestReceived();
    
    this->getServerAddress(arg_address.out(), arg_port);
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      msgsize = omni::align_to(msgsize, omni::ALIGN_4) + 4;
      msgsize += ((const char*) arg_address) ? strlen((const char*) arg_address) + 1 : 1;
      
      msgsize = omni::align_to(msgsize, omni::ALIGN_2) + 2;
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
      {
        CORBA::ULong _len = (((const char*) arg_address)? strlen((const char*) arg_address) + 1 : 1);
        
        _len >>= giop_s;
        if (_len > 1)
          giop_s.put_char_array((const CORBA::Char *)((const char*)arg_address),_len);
        else {
          if ((const char*) arg_address == 0 && omniORB::traceLevel > 1)
            _CORBA_null_string_ptr(0);
          CORBA::Char('\0') >>= giop_s;
        }
      }
      arg_port >>= giop_s;
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "getDesktopSize") ) {
    
    CORBA::UShort arg_width;
    
    CORBA::UShort arg_height;
    
    CORBA::UShort arg_depth;
    
    giop_s.RequestReceived();
    
    this->getDesktopSize(arg_width, arg_height, arg_depth);
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      msgsize = omni::align_to(msgsize, omni::ALIGN_2) + 2;
      
      msgsize = omni::align_to(msgsize, omni::ALIGN_2) + 2;
      
      msgsize = omni::align_to(msgsize, omni::ALIGN_2) + 2;
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
      arg_width >>= giop_s;
      arg_height >>= giop_s;
      arg_depth >>= giop_s;
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "initiateConnection") ) {
    static const char* const _user_exns[] = {
      "IDL:vnc/connectionFailed:1.0"
    };
    giop_s.set_user_exceptions(_user_exns, 1);
    
    CORBA::String_var arg_clientAddress;
    
    {
      CORBA::String_member _0RL_str_tmp;
      _0RL_str_tmp <<=  giop_s;
      arg_clientAddress = _0RL_str_tmp._ptr;
      _0RL_str_tmp._ptr = 0;
    }
    CORBA::UShort arg_port;
    
    arg_port <<= giop_s;
    CORBA::UShort arg_capability;
    
    arg_capability <<= giop_s;
    CORBA::Boolean arg_enableInputs;
    
    arg_enableInputs <<= giop_s;
    CORBA::Boolean arg_isTeleport;
    
    arg_isTeleport <<= giop_s;
    
    giop_s.RequestReceived();
    CORBA::UShort result;
    
#ifndef HAS_Cplusplus_catch_exception_by_base
    try {
#endif
    
    result = this->initiateConnection(arg_clientAddress.in(), arg_port, arg_capability, arg_enableInputs, arg_isTeleport);
#ifndef HAS_Cplusplus_catch_exception_by_base
    }
    
    catch(vnc::connectionFailed& ex) {
      throw omniORB::StubUserException(ex._NP_duplicate());
    }
    
#endif
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      msgsize = omni::align_to(msgsize, omni::ALIGN_2) + 2;
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      result >>= giop_s;
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "closeConnection") ) {
    
    CORBA::UShort arg_connectionId;
    
    arg_connectionId <<= giop_s;
    
    giop_s.RequestReceived();
    
    this->closeConnection(arg_connectionId);
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "getTimeSinceLastConnection") ) {
    
    giop_s.RequestReceived();
    CORBA::ULong result;
    
    result = this->getTimeSinceLastConnection();
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      msgsize = omni::align_to(msgsize, omni::ALIGN_4) + 4;
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      result >>= giop_s;
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "shutdown") ) {
    
    giop_s.RequestReceived();
    
    this->shutdown();
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "enableKeyboardDevice") ) {
    
    CORBA::UShort arg_periperalId;
    
    arg_periperalId <<= giop_s;
    
    giop_s.RequestReceived();
    
    this->enableKeyboardDevice(arg_periperalId);
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "disableKeyboardDevice") ) {
    
    CORBA::UShort arg_peripheralId;
    
    arg_peripheralId <<= giop_s;
    
    giop_s.RequestReceived();
    
    this->disableKeyboardDevice(arg_peripheralId);
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "enablePointerDevice") ) {
    
    CORBA::UShort arg_periperalId;
    
    arg_periperalId <<= giop_s;
    
    giop_s.RequestReceived();
    
    this->enablePointerDevice(arg_periperalId);
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "disablePointerDevice") ) {
    
    CORBA::UShort arg_peripheralId;
    
    arg_peripheralId <<= giop_s;
    
    giop_s.RequestReceived();
    
    this->disablePointerDevice(arg_peripheralId);
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  return 0;
}

void*
vnc::_impl_controller::_ptrToInterface(const char* id)
{
  if( !strcmp(id, CORBA::Object::_PD_repoId) )
    return (void*) 1;
  if( !strcmp(id, vnc::controller::_PD_repoId) )
    return (_impl_controller*) this;
  
  return 0;
}

const char*
vnc::_impl_controller::_mostDerivedRepoId()
{
  return vnc::controller::_PD_repoId;
}

vnc::watch_ptr vnc::watch_Helper::_nil() {
  return vnc::watch::_nil();
}

CORBA::Boolean vnc::watch_Helper::is_nil(vnc::watch_ptr p) {
  return CORBA::is_nil(p);

}

void vnc::watch_Helper::release(vnc::watch_ptr p) {
  CORBA::release(p);
}

void vnc::watch_Helper::duplicate(vnc::watch_ptr p) {
  if( p && !p->_NP_is_nil() )  omni::duplicateObjRef(p);
}

size_t vnc::watch_Helper::NP_alignedSize(vnc::watch_ptr obj, size_t offset) {
  return vnc::watch::_alignedSize(obj, offset);
}

void vnc::watch_Helper::marshalObjRef(vnc::watch_ptr obj, NetBufferedStream& s) {
  vnc::watch::_marshalObjRef(obj, s);
}

vnc::watch_ptr vnc::watch_Helper::unmarshalObjRef(NetBufferedStream& s) {
  return vnc::watch::_unmarshalObjRef(s);
}

void vnc::watch_Helper::marshalObjRef(vnc::watch_ptr obj, MemBufferedStream& s) {
  vnc::watch::_marshalObjRef(obj, s);
}

vnc::watch_ptr vnc::watch_Helper::unmarshalObjRef(MemBufferedStream& s) {
  return vnc::watch::_unmarshalObjRef(s);
}

vnc::watch_ptr
vnc::watch::_duplicate(vnc::watch_ptr obj)
{
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);

  return obj;
}

vnc::watch_ptr
vnc::watch::_narrow(CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}

vnc::watch_ptr
vnc::watch::_nil()
{
  static _objref_watch* _the_nil_ptr = 0;
  if( !_the_nil_ptr ) {
    omni::nilRefLock().lock();
  if( !_the_nil_ptr )  _the_nil_ptr = new _objref_watch;
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
}

const char* vnc::watch::_PD_repoId = "IDL:vnc/watch:1.0";

vnc::_objref_watch::~_objref_watch() {}

vnc::_objref_watch::_objref_watch(const char* mdri,
   IOP::TaggedProfileList* p, omniIdentity* id, omniLocalIdentity* lid) :
   
   omniObjRef(vnc::watch::_PD_repoId, mdri, p, id, lid)
{
  _PR_setobj(this);
}

void*
vnc::_objref_watch::_ptrToObjRef(const char* id)
{
  if( !strcmp(id, CORBA::Object::_PD_repoId) )
    return (CORBA::Object_ptr) this;
  if( !strcmp(id, vnc::watch::_PD_repoId) )
    return (vnc::watch_ptr) this;
  
  return 0;
}

// Proxy call descriptor class. Mangled signature:
//  _cstring
class _0RL_cd_22cbff1b827fd898_21000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_22cbff1b827fd898_21000000(LocalCallFn lcfn, const char* op, size_t oplen, _CORBA_Boolean oneway):
     omniCallDescriptor(lcfn, op, oplen, oneway) {}

  virtual void unmarshalReturnedValues(GIOP_C&);
    
  inline char * result() { return pd_result; }
  
  char * pd_result;
};

void _0RL_cd_22cbff1b827fd898_21000000::unmarshalReturnedValues(GIOP_C& giop_client)
{
  
  {
    CORBA::String_member _0RL_str_tmp;
    _0RL_str_tmp <<=  giop_client;
    pd_result = _0RL_str_tmp._ptr;
    _0RL_str_tmp._ptr = 0;
  }
  
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_31000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_22cbff1b827fd898_21000000* tcd = (_0RL_cd_22cbff1b827fd898_21000000*) cd;
  vnc::_impl_watch* impl = (vnc::_impl_watch*) svnt->_ptrToInterface(vnc::watch::_PD_repoId);
  tcd->pd_result = impl->getHost();
}

char* vnc::_objref_watch::getHost()
{
  _0RL_cd_22cbff1b827fd898_21000000 _call_desc(_0RL_lcfn_22cbff1b827fd898_31000000, "getHost", 8, 0);
  
  _invoke(_call_desc);
  return _call_desc.result();
}

// Local call call-back function.
static void
_0RL_lcfn_22cbff1b827fd898_41000000(omniCallDescriptor* cd, omniServant* svnt)
{
  
  vnc::_impl_watch* impl = (vnc::_impl_watch*) svnt->_ptrToInterface(vnc::watch::_PD_repoId);
  impl->shutdown();
}

void vnc::_objref_watch::shutdown()
{
  omniStdCallDesc::void_call _call_desc(_0RL_lcfn_22cbff1b827fd898_41000000, "shutdown", 9, 1/*oneway*/);
  
  _invoke(_call_desc);
  
}

vnc::_pof_watch::~_pof_watch() {}

omniObjRef*
vnc::_pof_watch::newObjRef(const char* mdri, IOP::TaggedProfileList* p,
               omniIdentity* id, omniLocalIdentity* lid)
{
  return new vnc::_objref_watch(mdri, p, id, lid);
}

CORBA::Boolean
vnc::_pof_watch::is_a(const char* id) const
{
  if( !strcmp(id, vnc::watch::_PD_repoId) )
    return 1;
  
  return 0;
}

const vnc::_pof_watch _the_pof_vnc_mwatch;

vnc::_impl_watch::~_impl_watch() {}

CORBA::Boolean
vnc::_impl_watch::_dispatch(GIOP_S& giop_s)
{
  if( !strcmp(giop_s.operation(), "getHost") ) {
    
    giop_s.RequestReceived();
    CORBA::String_var result;
    
    result = this->getHost();
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      msgsize = omni::align_to(msgsize, omni::ALIGN_4) + 4;
      msgsize += ((const char*) result) ? strlen((const char*) result) + 1 : 1;
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      {
        CORBA::ULong _len = (((const char*) result)? strlen((const char*) result) + 1 : 1);
        
        _len >>= giop_s;
        if (_len > 1)
          giop_s.put_char_array((const CORBA::Char *)((const char*)result),_len);
        else {
          if ((const char*) result == 0 && omniORB::traceLevel > 1)
            _CORBA_null_string_ptr(0);
          CORBA::Char('\0') >>= giop_s;
        }
      }
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  if( !strcmp(giop_s.operation(), "shutdown") ) {
    
    giop_s.RequestReceived();
    
    this->shutdown();
    
    if( giop_s.response_expected() ) {
      size_t msgsize = (size_t) GIOP_S::ReplyHeaderSize();
      
      giop_s.InitialiseReply(GIOP::NO_EXCEPTION, (CORBA::ULong) msgsize);
      
    }
    giop_s.ReplyCompleted();
    return 1;
  }

  return 0;
}

void*
vnc::_impl_watch::_ptrToInterface(const char* id)
{
  if( !strcmp(id, CORBA::Object::_PD_repoId) )
    return (void*) 1;
  if( !strcmp(id, vnc::watch::_PD_repoId) )
    return (_impl_watch*) this;
  
  return 0;
}

const char*
vnc::_impl_watch::_mostDerivedRepoId()
{
  return vnc::watch::_PD_repoId;
}

POA_vnc::controller::~controller() {}

POA_vnc::watch::~watch() {}

