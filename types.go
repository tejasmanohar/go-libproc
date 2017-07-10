package libproc

// Pid is a process ID.
type Pid uint32

// PidInfoFlavor determines the return type of proc_pidinfo.
type PidInfoFlavor int

const (
	// ProcPidlistfds - proc_info.h: PROC_PIDLISTFDS
	ProcPidlistfds PidInfoFlavor = 1
	// ProcPidtaskallinfo - proc_info.h: PROC_PIDTASKALLINFO
	ProcPidtaskallinfo = 2
	// ProcPidtbsdinfo - proc_info.h: PROC_PIDTBSDINFO
	ProcPidtbsdinfo = 3
	// ProcPidtaskinfo - proc_info.h: PROC_PIDTASKINFO
	ProcPidtaskinfo = 4
	// ProcPidthreadinfo - proc_info.h: PROC_PIDTHREADINFO
	ProcPidthreadinfo = 5
	// ProcPidlistthreads - proc_info.h: PROC_PIDLISTTHREADS
	ProcPidlistthreads = 6
	// ProcPidregioninfo - proc_info.h: PROC_PIDREGIONINFO
	ProcPidregioninfo = 7
	// ProcPidregionpathinfo - proc_info.h: PROC_PIDREGIONPATHINFO
	ProcPidregionpathinfo = 8
	// ProcPidvnodepathinfo - proc_info.h: PROC_PIDVNODEPATHINFO
	ProcPidvnodepathinfo = 9
	// ProcPidthreadpathinfo - proc_info.h: PROC_PIDTHREADPATHINFO
	ProcPidthreadpathinfo = 10
	// ProcPidpathinfo - proc_info.h: PROC_PIDPATHINFO
	ProcPidpathinfo = 11
	// ProcPidworkqueueinfo - proc_info.h: PROC_PIDWORKQUEUEINFO
	ProcPidworkqueueinfo = 12
	// ProcPidtShortbsdinfo - proc_info.h: PROC_PIDT_SHORTBSDINFO
	ProcPidtShortbsdinfo = 13
	// ProcPidlistfileports - proc_info.h: PROC_PIDLISTFILEPORTS
	ProcPidlistfileports = 14
	// ProcPidthreadid64Info - proc_info.h: PROC_PIDTHREADID64INFO
	ProcPidthreadid64Info = 15
	// ProcPidRusage - proc_info.h: PROC_PID_RUSAGE
	ProcPidRusage = 16
)

// PidFdInfoFlavor determines the return type of proc_pidfdinfo.
type PidFdInfoFlavor int

const (
	// ProcPidfdvnodeinfo - proc_info.h: PROC_PIDFDVNODEINFO
	ProcPidfdvnodeinfo PidInfoFlavor = 1
	// ProcPidfdvnodepathinfo - proc_info.h: PROC_PIDFDVNODEPATHINFO
	ProcPidfdvnodepathinfo = 2
	// ProcPidfdsocketinfo - proc_info.h: PROC_PIDFDSOCKETINFO
	ProcPidfdsocketinfo = 3
	// ProcPidfdpseminfo - proc_info.h: PROC_PIDFDPSEMINFO
	ProcPidfdpseminfo = 4
	// ProcPidfdpshminfo - proc_info.h: PROC_PIDFDPSHMINFO
	ProcPidfdpshminfo = 5
	// ProcPidfdpipeinfo - proc_info.h: PROC_PIDFDPIPEINFO
	ProcPidfdpipeinfo = 6
	// ProcPidfdkqueueinfo - proc_info.h: PROC_PIDFDKQUEUEINFO
	ProcPidfdkqueueinfo = 7
	// ProcPidfdatalkinfo - proc_info.h: PROC_PIDFDATALKINFO
	ProcPidfdatalkinfo = 8
)

// PidFileReportInfoFlavor determines the return type of proc_pidfileportinfo.
type PidFileReportInfoFlavor int

const (
	// ProcPidfileportvnodepathinfo - proc_info.h: PROC_PIDFILEPORTVNODEPATHINFO
	ProcPidfileportvnodepathinfo PidFileReportInfoFlavor = 2 /* out: vnode_fdinfowithpath */
	// ProcPidfileportsocketinfo - proc_info.h: PROC_PIDFILEPORTSOCKETINFO
	ProcPidfileportsocketinfo = 3 /* out: socket_fdinfo */
	// ProcPidfileportpshminfo - proc_info.h: PROC_PIDFILEPORTPSHMINFO
	ProcPidfileportpshminfo = 5 /* out: pshm_fdinfo */
	// ProcPidfileportpipeinfo - proc_info.h: PROC_PIDFILEPORTPIPEINFO
	ProcPidfileportpipeinfo = 6 /* out: pipe_fdinfo */
)

// ProcessControl is an input enum for proc_setpcontrol.
type ProcessControl int

const (
	// ProcSelfsetPcontrol - proc_info.h: PROC_SELFSET_PCONTROL
	ProcSelfsetPcontrol ProcessControl = 1
	// ProcSelfsetThreadname - proc_info.h: PROC_SELFSET_THREADNAME
	ProcSelfsetThreadname = 2
	// ProcSelfsetVmrsrcowner - proc_info.h: PROC_SELFSET_VMRSRCOWNER
	ProcSelfsetVmrsrcowner = 3
	// ProcSelfsetDelayidlesleep - proc_info.h: PROC_SELFSET_DELAYIDLESLEEP
	ProcSelfsetDelayidlesleep = 4
)

// TrackDirtyFlag is an enum for possible flags in proc_track_dirty.
type TrackDirtyFlag uint32

const (
	// ProcDirtyTrack - proc_info.h: PROC_DIRTY_TRACK
	ProcDirtyTrack TrackDirtyFlag = 0x1
	// ProcDirtyAllowIdleExit - proc_info.h: PROC_DIRTY_ALLOW_IDLE_EXIT
	ProcDirtyAllowIdleExit = 0x2
	// ProcDirtyDefer - proc_info.h: PROC_DIRTY_DEFER
	ProcDirtyDefer = 0x4
	// ProcDirtyLaunchInProgress - proc_info.h: PROC_DIRTY_LAUNCH_IN_PROGRESS
	ProcDirtyLaunchInProgress = 0x8
)

// GetDirtyFlag is an enum for possible flags in proc_get_dirty.
type GetDirtyFlag uint32

const (
	// ProcDirtyTracked - proc_info.h: PROC_DIRTY_TRACKED
	ProcDirtyTracked GetDirtyFlag = 0x1
	// ProcDirtyAllowsIdleExit - proc_info.h: PROC_DIRTY_ALLOWS_IDLE_EXIT
	ProcDirtyAllowsIdleExit = 0x2
	// ProcDirtyIsDirty - proc_info.h: PROC_DIRTY_IS_DIRTY
	ProcDirtyIsDirty = 0x4
	// ProcDirtyLaunchIsInProgress - proc_info.h: PROC_DIRTY_LAUNCH_IS_IN_PROGRESS
	ProcDirtyLaunchIsInProgress = 0x8
)

// RUsageFlavor determines the return type of proc_pid_rusage.
// TODO: find available inputs
type RUsageFlavor int
