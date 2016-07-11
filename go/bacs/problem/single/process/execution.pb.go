// Code generated by protoc-gen-go.
// source: bacs/problem/single/process/execution.proto
// DO NOT EDIT!

/*
Package process is a generated protocol buffer package.

It is generated from these files:
	bacs/problem/single/process/execution.proto
	bacs/problem/single/process/file.proto
	bacs/problem/single/process/settings.proto

It has these top-level messages:
	Execution
	File
	Settings
*/
package process

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"
import bacs_file "github.com/bacsorg/common/go/bacs/file"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

type Execution_Redirection_Stream int32

const (
	Execution_Redirection_STDIN  Execution_Redirection_Stream = 0
	Execution_Redirection_STDOUT Execution_Redirection_Stream = 1
	Execution_Redirection_STDERR Execution_Redirection_Stream = 2
)

var Execution_Redirection_Stream_name = map[int32]string{
	0: "STDIN",
	1: "STDOUT",
	2: "STDERR",
}
var Execution_Redirection_Stream_value = map[string]int32{
	"STDIN":  0,
	"STDOUT": 1,
	"STDERR": 2,
}

func (x Execution_Redirection_Stream) String() string {
	return proto.EnumName(Execution_Redirection_Stream_name, int32(x))
}

type Execution struct {
	Argument    []string                 `protobuf:"bytes,1,rep,name=argument" json:"argument,omitempty"`
	CurrentPath *bacs_file.Path          `protobuf:"bytes,2,opt,name=current_path" json:"current_path,omitempty"`
	Redirection []*Execution_Redirection `protobuf:"bytes,3,rep,name=redirection" json:"redirection,omitempty"`
}

func (m *Execution) Reset()         { *m = Execution{} }
func (m *Execution) String() string { return proto.CompactTextString(m) }
func (*Execution) ProtoMessage()    {}

func (m *Execution) GetCurrentPath() *bacs_file.Path {
	if m != nil {
		return m.CurrentPath
	}
	return nil
}

func (m *Execution) GetRedirection() []*Execution_Redirection {
	if m != nil {
		return m.Redirection
	}
	return nil
}

type Execution_Redirection struct {
	Stream Execution_Redirection_Stream `protobuf:"varint,1,opt,name=stream,enum=bacs.problem.single.process.Execution_Redirection_Stream" json:"stream,omitempty"`
	FileId string                       `protobuf:"bytes,2,opt,name=file_id" json:"file_id,omitempty"`
}

func (m *Execution_Redirection) Reset()         { *m = Execution_Redirection{} }
func (m *Execution_Redirection) String() string { return proto.CompactTextString(m) }
func (*Execution_Redirection) ProtoMessage()    {}

func init() {
	proto.RegisterEnum("bacs.problem.single.process.Execution_Redirection_Stream", Execution_Redirection_Stream_name, Execution_Redirection_Stream_value)
}