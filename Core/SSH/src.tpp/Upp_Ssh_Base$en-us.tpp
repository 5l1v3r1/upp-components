topic "Base";
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
[ {{10000@(113.42.0) [s0;%% [*@7;4 Ssh]]}}&]
[s3; &]
[s1;:Upp`:`:Ssh`:`:class: [@(0.0.255)3 class][3 _][*3 Ssh]&]
[s2;#%% This is the base class of SSH2 session and channel related 
classes. It provides support for time`-constrained blocking and 
non`-blocking operations, polymorphism, [^https`:`/`/en`.wikipedia`.org`/wiki`/Run`-time`_type`_information`?oldformat`=true^ R
TTI], error management, and logging.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Method List]]}}&]
[s3;%% &]
[s5;:Upp`:`:Ssh`:`:Do`(`): [@(0.0.255) bool]_[* Do]()&]
[s2;%% Progresses the request in non`-blocking mode. Cannot be called 
in blocking mode. Returns true if the request is still in progress.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:Wait`(int`): [@(0.0.255) bool]_[* Wait]([@(0.0.255) int]_[*@3 ms]_`=_[@3 10])
&]
[s2;%% Encapsulates a POSIX select() call. Waits [%-*@3 ms] miliseconds 
for read and write events for the associated session socket. 
Returns true if an event is signalled. Intented to be used in 
non`-blocking mode.&]
[s3;%% &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:Cancel`(`): [@(0.0.255) void]_[* Cancel]()&]
[s2;%% Cancels the current request.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:GetTimeout`(`)const: [@(0.0.255) int]_[* GetTimeout]()_[@(0.0.255) const
]&]
[s2;%% Returns the timeout value.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:IsError`(`)const: [@(0.0.255) bool]_[* IsError]()_[@(0.0.255) const]&]
[s2;%% Returns true if there was an error.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:GetError`(`)const: [@(0.0.255) int]_[* GetError]()_[@(0.0.255) const]&]
[s2;%% Returns the last error code if any.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:GetErrorDesc`(`)const: [_^Upp`:`:String^ String]_[* GetErrorDesc]()_[@(0.0.255) c
onst]&]
[s2;%% Returns the last error message if any.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:GetId`(`)const: [_^Upp`:`:int64^ int64]_[* GetId]()_[@(0.0.255) const]&]
[s2;%% Returns the unique id of the object. Each ssh object is assigned 
a unique id on construction.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:GetType`(`)const: [@(0.0.255) int]_[* GetType]()_[@(0.0.255) const]&]
[s0;l288;%% Returns the ssh object type identifier. Currently it 
can be one of the following: SESSION, SFTP, SCP, CHANNEL, EXEC, 
SHELL&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:To`(`): [@(0.0.255) template]_<[@(0.0.255) class]_[*@4 T]>_[*@4 T][@(0.0.255) `&
]_[* To]()&]
[s0;l288;%% Converts the ssh object to [%-*@4 T]. [%-*@4 T] can be one 
of the Ssh`-based classes. Returns a reference to [%-*@4 T] on 
success. &]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:Is`(`)const: [@(0.0.255) template]_<[@(0.0.255) class]_[*@4 T]>_[@(0.0.255) b
ool]_[* Is]()_[@(0.0.255) const]&]
[s2; [%% Tests whether the ssh`-based object is of type ][*@4 T]&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ssh`:`:Trace`(bool`): [@(0.0.255) static] [@(0.0.255) void]_[* Trace]([@(0.0.255) b
ool]_[*@3 b]_`=_[@(0.0.255) true])&]
[s2;%% Enables or disables logging.&]
[s0; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:Ssh`:`:Ssh`(`): [* Ssh]()&]
[s2;%% Default constructor.&]
[s0;%% ]]