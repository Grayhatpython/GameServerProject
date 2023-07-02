// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Enum.proto

#include "Enum.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace Protocol {
}  // namespace Protocol
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_Enum_2eproto[9];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_Enum_2eproto = nullptr;
const uint32_t TableStruct_Enum_2eproto::offsets[1] = {};
static constexpr ::_pbi::MigrationSchema* schemas = nullptr;
static constexpr ::_pb::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_Enum_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\nEnum.proto\022\010Protocol*X\n\017ClientGameStat"
  "e\022\026\n\022CLIENT_STATE_LOGIN\020\000\022\026\n\022CLIENT_STAT"
  "E_LOBBY\020\001\022\025\n\021CLIENT_STATE_GAME\020\002*J\n\tActo"
  "rType\022\010\n\004NONE\020\000\022\n\n\006PLAYER\020\001\022\013\n\007MONSTER\020\002"
  "\022\016\n\nPROJECTILE\020\003\022\n\n\006EFFECT\020\004*3\n\007AIState\022"
  "\010\n\004IDLE\020\000\022\010\n\004MOVE\020\001\022\t\n\005Skill\020\002\022\t\n\005DEATH\020"
  "\003*O\n\tSkillType\022\016\n\nSKILL_NONE\020\000\022\025\n\021SKILL_"
  "AUTO_ATTACK\020\001\022\033\n\027SKILL_PROJECTILE_ATTACK"
  "\020\002*c\n\010ItemType\022\022\n\016ITEM_TYPE_NONE\020\000\022\024\n\020IT"
  "EM_TYPE_WEAPON\020\001\022\023\n\017ITEM_TYPE_ARMOR\020\002\022\030\n"
  "\024ITEM_TYPE_CONSUMABLE\020\003*O\n\nWeaponType\022\024\n"
  "\020WEAPON_TYPE_NONE\020\000\022\025\n\021WEAPON_TYPE_SWORD"
  "\020\001\022\024\n\020WEAPON_TYPE_BOOK\020\002*c\n\tArmorType\022\023\n"
  "\017ARMOR_TYPE_NONE\020\000\022\025\n\021ARMOR_TYPE_HELMET\020"
  "\001\022\024\n\020ARMOR_TYPE_ARMOR\020\002\022\024\n\020ARMOR_TYPE_BO"
  "OTS\020\003*G\n\016ConsumableType\022\030\n\024CONSUMABLE_TY"
  "PE_NONE\020\000\022\033\n\027CONSUMABLE_TYPE_PORTION\020\001*j"
  "\n\007MoveDir\022\006\n\002UP\020\000\022\010\n\004DOWN\020\001\022\010\n\004LEFT\020\002\022\t\n"
  "\005RIGHT\020\003\022\014\n\010UP_RIGHT\020\004\022\013\n\007UP_LEFT\020\005\022\016\n\nD"
  "OWN_RIGHT\020\006\022\r\n\tDOWN_LEFT\020\007b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_Enum_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_Enum_2eproto = {
    false, false, 794, descriptor_table_protodef_Enum_2eproto,
    "Enum.proto",
    &descriptor_table_Enum_2eproto_once, nullptr, 0, 0,
    schemas, file_default_instances, TableStruct_Enum_2eproto::offsets,
    nullptr, file_level_enum_descriptors_Enum_2eproto,
    file_level_service_descriptors_Enum_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_Enum_2eproto_getter() {
  return &descriptor_table_Enum_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_Enum_2eproto(&descriptor_table_Enum_2eproto);
namespace Protocol {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ClientGameState_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[0];
}
bool ClientGameState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ActorType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[1];
}
bool ActorType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* AIState_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[2];
}
bool AIState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SkillType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[3];
}
bool SkillType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ItemType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[4];
}
bool ItemType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* WeaponType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[5];
}
bool WeaponType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ArmorType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[6];
}
bool ArmorType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ConsumableType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[7];
}
bool ConsumableType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MoveDir_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[8];
}
bool MoveDir_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>