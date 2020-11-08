package hello.hellospring.aop;

@Aspect
public class TimeTraceAop {

    @Around("execution(* hello.hellospring..*(..))")
    public Object execute(ProceedingJoinPoint joinPoint) throws Throwable {

        long start = system.currentTimeMillis();

        System.out.println("start = " + joinPoint.toStirng());

        try {
            return joinPoint.proceed();
        } finally {
            long finish = System.currentTimeMillis();
            long timeMs = finish - start;

            System.out.println("End: = " + joinPoint.toString() + " " + timeMs + "ms");
        }
    }
}
