package spring.HH.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import spring.HH.domain.Block;

public interface BlockRepository extends JpaRepository<Block, Long> {
}
