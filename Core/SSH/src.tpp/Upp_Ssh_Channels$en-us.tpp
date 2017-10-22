topic "Channels";
[2 $$0,0#00000000000000000000000000000000:Default]
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[{_} 
[ {{10000@(113.42.0) [s0;%% [*@7;4 SshExec]]}}&]
[s3; &]
[s1;:Upp`:`:SshExec`:`:class: [@(0.0.255)3 class][3 _][*3 SshExec][3 _:_][@(0.0.255)3 public][3 _][*@3;3 S
shChannel]&]
[s0;#l288;%% This class encapsulates an SSH2 remote process execution 
(exec) channel. It provides a means for executing processes on 
remote hosts. SshExec class is derived from SshChannel class, 
and has pick semantics.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Method List]]}}&]
[s3; &]
[s5;:Upp`:`:SshExec`:`:Execute`(const Upp`:`:String`&`,Upp`:`:Stream`&`,Upp`:`:Stream`&`): [@(0.0.255) i
nt]_[* Execute]([@(0.0.255) const]_[_^Upp`:`:String^ String][@(0.0.255) `&]_[*@3 cmd], 
[_^Upp`:`:Stream^ Stream][@(0.0.255) `&]_[*@3 out], [_^Upp`:`:Stream^ Stream][@(0.0.255) `&
]_[*@3 err])&]
[s5;:Upp`:`:SshExec`:`:operator`(`)`(const Upp`:`:String`&`,Upp`:`:Stream`&`,Upp`:`:Stream`&`): [@(0.0.255) i
nt]_[* operator()]([@(0.0.255) const]_[_^Upp`:`:String^ String][@(0.0.255) `&]_[*@3 cmd], 
[_^Upp`:`:Stream^ Stream][@(0.0.255) `&]_[*@3 out], [_^Upp`:`:Stream^ Stream][@(0.0.255) `&
]_[*@3 err])&]
[s0;l288;%% Executes remote process defined by [%-*@3 cmd] command 
line, returns its standard output in [%-*@3 out], its standard 
error output in [%-*@3 err], and its exit code as return value. 
&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:SshExec`:`:SshExec`(Upp`:`:SshSession`&`): [* SshExec]([_^Upp`:`:SshSession^ S
shSession][@(0.0.255) `&]_[*@3 session])&]
[s0;l288;%% Constructor. Binds the SshExec instance to [%-*@3 session].&]
[s3; &]
[s0; &]
[ {{10000@(113.42.0) [s0;%% [*@7;4 Scp]]}}&]
[s3;%% &]
[s1;:Upp`:`:Scp`:`:class: [@(0.0.255)3 class][3 _][*3 Scp][3 _:_][@(0.0.255)3 public][3 _][*@3;3 Ssh
Channel]&]
[s0;#l288;%% This class encapsulates an SSH2 secure copy channel. 
It provides a means for securely transferring files between local 
host and a remote host. Scp class is derived from SshChannel 
class, and has pick semantics.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Scp`:`:Get`(Upp`:`:Stream`&`,const Upp`:`:String`&`,Upp`:`:Gate`<Upp`:`:int64`,Upp`:`:int64`>`): [@(0.0.255) b
ool]_[* Get]([_^Upp`:`:Stream^ Stream][@(0.0.255) `&]_[*@3 out], [@(0.0.255) const]_[_^Upp`:`:String^ S
tring][@(0.0.255) `&]_[*@3 path], [_^Upp`:`:Gate^ Gate]<[_^Upp`:`:int64^ int64], 
[_^Upp`:`:int64^ int64]>_[*@3 progress]_`=_Null)&]
[s5;:Upp`:`:Scp`:`:operator`(`)`(Upp`:`:Stream`&`,const Upp`:`:String`&`,Upp`:`:Gate`<Upp`:`:int64`,Upp`:`:int64`>`): [@(0.0.255) b
ool]_[* operator()]([_^Upp`:`:Stream^ Stream][@(0.0.255) `&]_[*@3 out], 
[@(0.0.255) const]_[_^Upp`:`:String^ String][@(0.0.255) `&]_[*@3 path], 
[_^Upp`:`:Gate^ Gate]<[_^Upp`:`:int64^ int64], [_^Upp`:`:int64^ int64]>_[*@3 progress]_`=
_Null)&]
[s0;l288;%% Downloads the remote file at [%-*@3 path] to local [%-*@3 out] 
. Returns true on success. [%-*@3 progress ]function can be used 
to track the progress of the download; returning true will abort 
the operation.&]
[s3;%% &]
[s4; &]
[s5;:Upp`:`:Scp`:`:Get`(const Upp`:`:String`&`,Upp`:`:Gate`<Upp`:`:int64`,Upp`:`:int64`>`): [_^Upp`:`:String^ S
tring]_[* Get]([@(0.0.255) const]_[_^Upp`:`:String^ String][@(0.0.255) `&]_[*@3 path], 
[_^Upp`:`:Gate^ Gate]<[_^Upp`:`:int64^ int64], [_^Upp`:`:int64^ int64]>_[*@3 progress]_`=
_Null)&]
[s5;:Upp`:`:Scp`:`:operator`(`)`(const Upp`:`:String`&`,Upp`:`:Gate`<Upp`:`:int64`,Upp`:`:int64`>`): [_^Upp`:`:String^ S
tring]_[* operator()]([@(0.0.255) const]_[_^Upp`:`:String^ String][@(0.0.255) `&]_[*@3 path
], [_^Upp`:`:Gate^ Gate]<[_^Upp`:`:int64^ int64], [_^Upp`:`:int64^ int64]>_[*@3 progress]_
`=_Null)&]
[s0;l288;%% Downloads the remote file at [%-*@3 path] and returns it 
as a String. Returns an empty string on failure. [%-*@3 progress] 
 function can be used to track the progress of the download; 
returning true will abort the operation.&]
[s3;%% &]
[s4; &]
[s5;:Upp`:`:Scp`:`:Put`(Upp`:`:Stream`&`,const Upp`:`:String`&`,long`,Upp`:`:Gate`<Upp`:`:int64`,Upp`:`:int64`>`): [@(0.0.255) b
ool]_[* Put]([_^Upp`:`:Stream^ Stream][@(0.0.255) `&]_[*@3 in], [@(0.0.255) const]_[_^Upp`:`:String^ S
tring][@(0.0.255) `&]_[*@3 path], [@(0.0.255) long]_[*@3 mode], [_^Upp`:`:Gate^ Gate]<[_^Upp`:`:int64^ i
nt64], [_^Upp`:`:int64^ int64]>_[*@3 progress]_`=_Null)&]
[s5;:Upp`:`:Scp`:`:operator`(`)`(Upp`:`:Stream`&`,const Upp`:`:String`&`,long`,Upp`:`:Gate`<Upp`:`:int64`,Upp`:`:int64`>`): [@(0.0.255) b
ool]_[* operator()]([_^Upp`:`:Stream^ Stream][@(0.0.255) `&]_[*@3 in], 
[@(0.0.255) const]_[_^Upp`:`:String^ String][@(0.0.255) `&]_[*@3 path], 
[@(0.0.255) long]_[*@3 mode], [_^Upp`:`:Gate^ Gate]<[_^Upp`:`:int64^ int64], 
[_^Upp`:`:int64^ int64]>_[*@3 progress]_`=_Null)&]
[s0;l288;%% Uploads the local data at [%-*@3 in] to remote [%-*@3 path] 
, with access [%-*@3 mode]. Returns true on success. [%-*@3 progress] 
function can be used to track the progress of the upload; returning 
true will abort the operation.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:Scp`:`:Scp`(Upp`:`:SshSession`&`): [* Scp]([_^Upp`:`:SshSession^ SshSession][@(0.0.255) `&
]_[*@3 session])&]
[s2;%% Constructor. Binds the Scp instance to [%-*@3 session].&]
[s3;%% &]
[s0;%% ]]